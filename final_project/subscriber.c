#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <cjson/cJSON.h>
#include "SSD1306/ssd1306.h"
#include "BMP280/bmp280.h"

void message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
    if (message->payloadlen)
    {
        printf("%s %s\n", message->topic, (char *)message->payload);
        cJSON *root = cJSON_Parse(message->payload);
        if (root)
        {
            const cJSON *task = cJSON_GetObjectItemCaseSensitive(root, "task");
            if (cJSON_IsString(task) && (task->valuestring != NULL))
            {
                if (strcmp(task->valuestring, "get_temperature") == 0)
                {
                    float temperature = bmp280_read_temperature();
                    ssd1306_clear();
                    ssd1306_printf("Temperature: %.2f C", temperature);
                    ssd1306_update();
                }
                else if (strcmp(task->valuestring, "get_pressure") == 0)
                {
                    float pressure = bmp280_read_pressure();
                    ssd1306_clear();
                    ssd1306_printf("Pressure: %.2f Pa", pressure);
                    ssd1306_update();
                }
                else if (strcmp(task->valuestring, "get_temperature_pressure") == 0)
                {
                    float temperature = bmp280_read_temperature();
                    float pressure = bmp280_read_pressure();
                    ssd1306_clear();
                    ssd1306_printf("Temperature: %.2f C\nPressure: %.2f Pa", temperature, pressure);
                    ssd1306_update();
                }
            }

            const cJSON *string_msg = cJSON_GetObjectItemCaseSensitive(root, "string_msg");
            if (cJSON_IsString(string_msg) && (string_msg->valuestring != NULL))
            {
                ssd1306_clear();
                ssd1306_printf("%s", string_msg->valuestring);
                ssd1306_update();
            }

            const cJSON *int_msg = cJSON_GetObjectItemCaseSensitive(root, "int_msg");
            if (cJSON_IsNumber(int_msg))
            {
                ssd1306_clear();
                ssd1306_printf("%d", int_msg->valueint);
                ssd1306_update();
            }

            cJSON_Delete(root);
        }
        else
        {
            printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        }
    }
    else
    {
        printf("%s (null)\n", message->topic);
    }
}

int main(int argc, char *argv[])
{
    struct mosquitto *mosq;

    // Initialize the Mosquitto library
    mosquitto_lib_init();

    // Create a new Mosquitto runtime instance with a random client ID
    mosq = mosquitto_new(NULL, true, NULL);
    if (!mosq)
    {
        fprintf(stderr, "Could not create Mosquitto instance\n");
        exit(-1);
    }

    // Assign the message callback
    mosquitto_message_callback_set(mosq, message_callback);

    // Connect to an MQTT broker
    if (mosquitto_connect(mosq, "localhost", 1883, 60) != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "Could not connect to broker\n");
        exit(-1);
    }

    // Subscribe to the topic
    mosquitto_subscribe(mosq, NULL, "test/topic", 0);

    // Start the loop
    mosquitto_loop_start(mosq);

    printf("Press Enter to quit...\n");
    getchar();

    // Cleanup
    mosquitto_loop_stop(mosq, true);
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    return 0;
}

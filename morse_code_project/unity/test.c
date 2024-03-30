#include "unity.h"
#include "translate_to_morse.h"
#include "blink_led.h"

void setUp() {
    // set stuff up here
}

void tearDown() {  
}

void test_AlphabeticInput(void) {
    uint8_t phrase[] = "Hello";
    uint8_t* output = phraseToTranslate(phrase);

    uint8_t* expected = ".... . .-.. .-.. ---";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for numeric input
void test_NumericInput(void) {
    uint8_t phrase[] = "123";
    uint8_t* output = phraseToTranslate(phrase);
    
    // 123
    char* expected = ".---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for mixed alphanumeric input
void test_MixedAlphanumericInput(void)
{
    uint8_t phrase[] = "abc123";
    uint8_t* output = phraseToTranslate(phrase);

    // abc123
    char *expected = ".- -... -.-. .---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for mixed case input
void test_MixedCaseAlphanumericInput(void) {
    uint8_t phrase[] = "AbC123";
    uint8_t* output = phraseToTranslate(phrase);

    // AbC123
    char *expected = ".- -... -.-. .---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for words with spaces
void test_CanHandleSpaces(void) {   
    uint8_t phrase[] = "Hello World";
    uint8_t* output = phraseToTranslate(phrase);

    // Hello World
    char *expected = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for non-representable binary data
void test_NonRepresentableBinaryData(void) {
    uint8_t phrase[] = {0x00, 0xFF, 0x55, 0x7F}; // Example binary data
    uint8_t* output = phraseToTranslate(phrase);

    TEST_ASSERT_EQUAL_STRING("", output);
}

/* Time Test */
void test_MorseTiming(void) {   
    uint8_t phrase[] = "SOS";
    uint32_t sleep_stats[2] = {0, 0};

    uint8_t* translation = phraseToTranslate(phrase); 
    blink_led(translation, sleep_stats);

    // Expected values
    int expected_delays = 17;
    int expected_delay_time = 27;

    // Assert the number of delay calls
    TEST_ASSERT_EQUAL(expected_delays, sleep_stats[0]);

    // Assert the total duration of delays
    TEST_ASSERT_EQUAL(expected_delay_time, sleep_stats[1]);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_AlphabeticInput);
    RUN_TEST(test_NumericInput);
    RUN_TEST(test_MixedAlphanumericInput);
    RUN_TEST(test_CanHandleSpaces);
    RUN_TEST(test_MixedCaseAlphanumericInput);
    RUN_TEST(test_NonRepresentableBinaryData);
    RUN_TEST(test_MorseTiming);
    UNITY_END();
}
#include "unity.h"
#include "translate_to_morse.h"

void setUp(void) {
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

void test_function_should_doAlsoDoBlah(void) {
    //more test stuff
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_AlphabeticInput);
    return UNITY_END();
}
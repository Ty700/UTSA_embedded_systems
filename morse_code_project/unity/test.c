#include "unity.h"
#include "translate_to_morse.h"

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
void test_NumericInput(void)
{
    uint8_t phrase[] = "123";
    uint8_t* output = phraseToTranslate(phrase);
    
    // 123
    char* expected = ".---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for mixed alphanumeric input
void test_MixedAlphanumericInput(void)
{

    char phrase[] = "abc123";
    uint8_t* output = phraseToTranslate(phrase);

    // abc123
    char *expected = ".- -... -.-. .---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for mixed case input
void test_MixedCaseAlphanumericInput(void)
{
    uint8_t phrase[] = "AbC123";
    uint8_t* output = phraseToTranslate(phrase);

    // AbC123
    char *expected = ".- -... -.-. .---- ..--- ...--";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for words with spaces
void test_CanHandleSpaces(void)
{   
    uint8_t phrase[] = "Hello World";
    uint8_t* output = phraseToTranslate(phrase);

    // Hello World
    char *expected = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";

    TEST_ASSERT_EQUAL_STRING(expected, output);
}

// Test function for non-representable binary data
void test_NonRepresentableBinaryData(void)
{
    uint8_t phrase[] = {0x00, 0xFF, 0x55, 0x7F}; // Example binary data
    uint8_t* output = phraseToTranslate(phrase);

    TEST_ASSERT_EQUAL_STRING("", output);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_AlphabeticInput);
    RUN_TEST(test_NumericInput);
    RUN_TEST(test_MixedAlphanumericInput);
    RUN_TEST(test_CanHandleSpaces);
    RUN_TEST(test_MixedCaseAlphanumericInput);
    RUN_TEST(test_NonRepresentableBinaryData);
    UNITY_END();
}
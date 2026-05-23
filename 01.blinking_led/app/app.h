#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sets up the user defined application
 */
void setup();

/**
 * @brief Runs the user defined application (loop) ==> LED blinking
 */
void led_blinking();

#ifdef __cplusplus
}
#endif

#endif // APP_H
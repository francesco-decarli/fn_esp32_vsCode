#ifndef APP_H
#define APP_H

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief Sets up the application. In particular, two GPIOs (led and button).
  */
void app_setup();

/**
  * @brief Runs the user defined application logic.
  */
void app_run();

#ifdef __cplusplus
}
#endif

#endif // APP_H
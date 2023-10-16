/**
 * @file main.cpp
 *
 * @brief This file contains the entry point for the application.
 */

#include <QApplication>
#include <QLabel>

/**
 * @brief The main function of the application.
 *
 * This function is the entry point for the application. It initializes the Qt
 * application, creates a QLabel widget with a "Hello, World!" message, shows
 * the widget, and enters the application event loop.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments as strings.
 *
 * @return The exit status of the application.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv); /**< Initialize the Qt application. */

    QLabel label("Hello, World!"); /**< Create a QLabel widget with a message. */
    label.show(); /**< Show the QLabel widget on the screen. */

    return app.exec(); /**< Enter the Qt application event loop. */
}

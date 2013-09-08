#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <application-cpp/gui.h>

#include "gui_test.h"

void GuiTest::clicking_the_send_button_signals_send_message_with_the_message_from_the_input_field()
{
    // arrange
    QPushButton send_button("send");
    QLineEdit message_input;

    IM::Gui testee(message_input, send_button);
    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    QString const expected_message = "Hello world.";
    message_input.setText(expected_message);

    // act
    QTest::mouseClick(&send_button, Qt::LeftButton);

    // assert
    QCOMPARE(signal_spy.count(), 1);

    const auto arguments = signal_spy.takeFirst();
    QCOMPARE(arguments.size(), 1);
    QCOMPARE(arguments.at(0).toString(), expected_message);
}

void GuiTest::clicking_the_send_button_does_not_signal_send_message_when_the_input_field_is_empty()
{
    // arrange
    QPushButton send_button("send");
    QLineEdit message_input;

    IM::Gui testee(message_input, send_button);
    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    message_input.clear();

    // act
    QTest::mouseClick(&send_button, Qt::LeftButton);

    // assert
    QCOMPARE(signal_spy.count(), 0);
}

void GuiTest::clicking_the_send_button_clears_the_input_field_is_empty()
{
    // arrange
    QPushButton send_button("send");
    QLineEdit message_input;

    IM::Gui testee(message_input, send_button);
    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    QString const expected_message = "Hello world.";
    message_input.setText(expected_message);

    // act
    QTest::mouseClick(&send_button, Qt::LeftButton);

    // assert
    QVERIFY(message_input.text().isEmpty());
}

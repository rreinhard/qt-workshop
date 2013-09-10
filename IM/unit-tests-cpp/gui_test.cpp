#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

#include <application-cpp/gui.h>

#include "gui_test.h"

void GuiTest::init()
{
    _send_button = new QPushButton("send");
    _message_input = new QLineEdit();
}

void GuiTest::clicking_the_send_button_signals_send_message_with_the_message_from_the_input_field()
{
    // arrange
    IM::Gui testee(_message_input, _send_button);
    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    QString const expected_message = "Hello world.";
    _message_input->setText(expected_message);

    // act
    QTest::mouseClick(_send_button, Qt::LeftButton);

    // assert
    QCOMPARE(signal_spy.count(), 1);

    const auto arguments = signal_spy.takeFirst();
    QCOMPARE(arguments.size(), 1);
    QCOMPARE(arguments.at(0).toString(), expected_message);
}

void GuiTest::clicking_the_send_button_does_not_signal_send_message_when_the_input_field_is_empty()
{
    // arrange
    IM::Gui testee(_message_input, _send_button);
    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    _message_input->clear();

    // act
    QTest::mouseClick(_send_button, Qt::LeftButton);

    // assert
    QCOMPARE(signal_spy.count(), 0);
}

void GuiTest::clicking_the_send_button_clears_the_input_field_is_empty()
{
    // arrange
    IM::Gui testee(_message_input, _send_button);
    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    QString const expected_message = "Hello world.";
    _message_input->setText(expected_message);

    // act
    QTest::mouseClick(_send_button, Qt::LeftButton);

    // assert
    QVERIFY(_message_input->text().isEmpty());
}


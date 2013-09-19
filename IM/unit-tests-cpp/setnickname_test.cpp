#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

#include "application-cpp/set_nickname_dialog.h"

#include "setnickname_test.h"

void SetNicknameTest::clicking_the_set_button_signals_set_nickname_with_the_name_from_the_input_field()
{
    QPushButton* set_button = new QPushButton("set nickname");
    QLineEdit* nickname_input = new QLineEdit();

    // arrange
    IM::SetNicknameDialog testee(nickname_input, set_button);
    QSignalSpy signal_spy(&testee, SIGNAL(set_nickname(QString const &)));

    QString const expected_nickname = "BugsBunny";
    nickname_input->setText(expected_nickname);

    // act
    QTest::mouseClick(set_button, Qt::LeftButton);

    // assert
    QCOMPARE(signal_spy.count(), 1);

    const auto arguments = signal_spy.takeFirst();
    QCOMPARE(arguments.size(), 1);
    QCOMPARE(arguments.at(0).toString(), expected_nickname);
}

void SetNicknameTest::clicking_the_set_button_does_not_signal_set_nickname_when_the_input_field_is_empty()
{
    QPushButton* set_button = new QPushButton("set nickname");
    QLineEdit* nickname_input = new QLineEdit();

    // arrange
    IM::SetNicknameDialog testee(nickname_input, set_button);
    QSignalSpy signal_spy(&testee, SIGNAL(set_nickname(QString const &)));

    nickname_input->clear();

    // act
    QTest::mouseClick(set_button, Qt::LeftButton);

    // assert
    QCOMPARE(signal_spy.count(), 0);
}

import QtQuick 2.0
import QtTest 1.0

import "utils.js" as Utils

import "../messenger/qml"

Item {
    width: 500
    height: 200

    Nickname {
        width: 250
        height: 50

        id: testee
    }

    SignalSpy {
        id: spy
        target: testee
    }

    TestCase {
        name: "Nickname field"
        when: windowShown

        function init() {
            spy.clear();
        }

        function test_has_a_property_nickname() {
            var expected_nickname = "hase";
            testee.nickname = expected_nickname;

            compare(testee.nickname, expected_nickname);
        }

        function test_text_of_the_input_field_is_stored_in_property_nickname() {
            var keys = [ Qt.Key_H, Qt.Key_A, Qt.Key_S, Qt.Key_E ];
            var expected_nickname = "hase";
            testee.nickname = "";

            var nick_input = Utils.get_item(testee, "id_nick_input");
            verify(nick_input);
            nick_input.focus = true;

            for(var i in keys) {
                keyClick(keys[i]);
            }

            compare(testee.nickname, expected_nickname);
        }

        function test_changing_the_nickname_sends_signal_nicknameChanged() {
            var keys = [ Qt.Key_H, Qt.Key_A, Qt.Key_S, Qt.Key_E ];
            testee.nickname = "";

            spy.signalName = "nicknameChanged";
            verify(spy.valid);

            var nick_input = Utils.get_item(testee, "id_nick_input");
            verify(nick_input);
            nick_input.focus = true;

            for(var i in keys) {
                keyClick(keys[i]);
            }

            compare(spy.count, 4);
        }
    }

}


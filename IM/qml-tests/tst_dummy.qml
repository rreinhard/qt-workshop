import QtQuick 2.0
import QtTest 1.0

import "utils.js" as Utils

Item {
    width: 100
    height: 62

    TestCase {
        name: "Dummy test case"

        function test_dummy() {
            verify(true);
        }
    }
}

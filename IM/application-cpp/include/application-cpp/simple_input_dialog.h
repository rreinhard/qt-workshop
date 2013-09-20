#ifndef SET_NICKNAME_DIALOG_H
#define SET_NICKNAME_DIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

namespace IM {

class SimpleInputDialog : public QDialog
{
    Q_OBJECT

public:
    SimpleInputDialog(const QString & title, QLineEdit* input_field, QPushButton* set_button, QWidget* parent = 0);

public slots:
    void handle_set_button_clicked();

signals:
    void set_input(const QString & nickname);

private:
    QVBoxLayout _layout;
    QLineEdit* _input_field;
    QPushButton* _set_button;

};

} //namespace IM

#endif // SET_NICKNAME_DIALOG_H

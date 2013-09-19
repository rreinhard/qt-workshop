#ifndef SET_NICKNAME_DIALOG_H
#define SET_NICKNAME_DIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>

namespace IM {

class SetNicknameDialog : public QDialog
{
    Q_OBJECT

public:
    SetNicknameDialog(QLineEdit* nickname_input, QPushButton* set_button, QWidget* parent = 0);

public slots:
    void handle_set_nickname_clicked();

signals:
    void set_nickname(QString const & nickname);

private:
    QVBoxLayout _layout;
    QLineEdit* _nickname_input;
    QPushButton* _set_button;

friend class SetNicknameTest;
    
};

} //namespace IM

#endif // SET_NICKNAME_DIALOG_H

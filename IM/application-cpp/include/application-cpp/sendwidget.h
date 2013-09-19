#ifndef SENDWIDGET_H
#define SENDWIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>

class QLineEdit;
class QPushButton;

namespace IM {

class SendWidget : public QWidget
{
    Q_OBJECT
public:
    SendWidget(QLineEdit * message_input,
               QPushButton * send_button,
               QWidget *parent = 0);

public slots:
    void handle_send_button_clicked();

signals:
    void send_message(quint32 command, QString const & message);

private:
    QHBoxLayout _layout;
    QLineEdit * _message_input;
    QPushButton * _send_button;
    
};

} // namespace IM

#endif // SENDWIDGET_H

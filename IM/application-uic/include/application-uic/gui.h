#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QWidget>

namespace Ui { class ImForm; }

namespace IM {

class Gui : public QWidget {
    Q_OBJECT

public:
    Gui(Ui::ImForm & form);

private slots:
    void on_send_button_clicked();

signals:
    void send_message(QString const & message);

private:
    Ui::ImForm & _im_form;
};

} // IM

#endif // GUI_H

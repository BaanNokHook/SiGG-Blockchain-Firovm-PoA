#ifndef SPLITUTXOPAGE_H
#define SPLITUTXOPAGE_H

#include <QDialog>

class WalletModel;
class ExecRPCCommand;

namespace Ui {
class SplitUTXOPage;
}

class SplitUTXOPage : public QDialog
{
    Q_OBJECT

public:
    enum Mode
    {
        Normal,
        Delegation,
        SuperStaker
    };

    explicit SplitUTXOPage(QWidget *parent = nullptr, Mode mode = Normal);
    ~SplitUTXOPage();
    void setModel(WalletModel *_model);
    void setAddress(const QString& address);
    bool isDataValid();
    void clearAll();

Q_SIGNALS:
    // Fired when a message should be reported to the user
    void message(const QString &title, const QString &message, unsigned int style);

public Q_SLOTS:
    void accept() override;
    void reject() override;

private Q_SLOTS:
    void updateDisplayUnit();
    void on_updateSplitCoinsButton();
    void on_splitCoinsClicked();
    void on_cancelButtonClicked();

private:
    Ui::SplitUTXOPage *ui;
    WalletModel* m_model;
    ExecRPCCommand *m_execRPCCommand;
    Mode m_mode;
    bool bCreateUnsigned = false;
};

#endif // SPLITUTXOPAGE_H

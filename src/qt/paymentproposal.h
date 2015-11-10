// Copyright (c) 2015 Jonas Schnelli
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DBB_PAYMENTPROPOSAL_H
#define DBB_PAYMENTPROPOSAL_H

#include <QWidget>
#include <univalue.h>

enum ProposalActionType
{
    ProposalActionTypeAccept,
    ProposalActionTypeReject
};

namespace Ui {
    class PaymentProposal;
}

class PaymentProposal : public QWidget
{
    Q_OBJECT

signals:
    void processProposal(const UniValue &proposalData, int actionType);
    void shouldDisplayProposal(const UniValue &pendingTxp, const std::string &proposalId);

public slots:
    void acceptPressed();
    void rejectPressed();
    void prevPressed();
    void nextPressed();

public:
    explicit PaymentProposal(QWidget *parent = 0);
    ~PaymentProposal();
    Ui::PaymentProposal *ui;
    void SetData(const std::string copayerID, const UniValue &pendingTxp, const UniValue &data, const std::string &prevID, const std::string &nextID);
private:
    UniValue pendingTxp;
    UniValue proposalData;
    std::string prevProposalID;
    std::string nextProposalID;
};

#endif // DBB_PAYMENTPROPOSAL_H

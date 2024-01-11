// Lim Jun Yan (BI20110128), Siow Wei Jun (BI20110084), Liew San Loong (BI20110105)

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class w_router : public cSimpleModule
{
  private:
    cMessage *message;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *message) override;
};

Define_Module(w_router);

void w_router::initialize()
{

}

void w_router::handleMessage(cMessage *message)
{
    if (message->getSenderModule() == getParentModule()->getSubmodule("Laptop1")) {

        // Message from Laptop1 to Laptop2
        cMessage *forwardMessage = new cMessage("CTS");
        cModule *target = getParentModule()->getSubmodule("Laptop2");
        sendDirect(forwardMessage, target, "radioIn");

    } else if (message->getSenderModule() == getParentModule()->getSubmodule("Laptop2")) {

        // Message from Laptop2 to Laptop1
        cMessage *forwardMessage = new cMessage("CTS");
        cModule *target = getParentModule()->getSubmodule("Laptop1");
        sendDirect(forwardMessage, target, "radioIn");

    } else {

        // Unexpected message source, delete the message
        EV << "Unexpected message source, deleting the message.\n";
        delete message;

    }
}

class pclaptop : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *message) override;
};

Define_Module(pclaptop);

void pclaptop::initialize()
{
    EV << "client initialize" << "\n";
    cMessage *message = new cMessage("RTS");
    scheduleAt(simTime() + dblrand(), message->dup());
    EV << "client initialize complete." << "\n";
}

void pclaptop::handleMessage(cMessage *message)
{
    EV << "client handle message initialize" << "\n";
    cModule *target;
    message = new cMessage("RTS");
    target = getParentModule()->getSubmodule("Router");
    sendDirect(message, target, "radioIn");
    scheduleAt(simTime() + dblrand(), message->dup());
}

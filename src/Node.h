/*
 * Node.h
 *
 *  Created on: 5 Nov 2013
 *      Author: Ata
 */

#ifndef NODE_H_
#define NODE_H_

class Node: public cSimpleModule
{
protected:

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    virtual void createNode(char* NodeName,char* NodePosition);
    virtual void eliminateNode(char* NodeName);

    virtual void checkSecurity();
    virtual void finish();
    virtual double calDistance(char* SourceNode,char* TargetNode);

private:
    long numSent;
    long numReceived;
    cLongHistogram hopCountStats;
    cOutVector hopCountVector;

};


#endif /* NODE_H_ */

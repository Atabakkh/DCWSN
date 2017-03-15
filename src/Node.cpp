/*
 * Node.cpp
 *
 *  Created on: 5 Nov 2013
 *      Author: Ata
 */

#include <string.h>
#include <omnetpp.h>
#include <stdio.h>
#include <Node.h>
#include <math.h>

Define_Module(Node);
enum Status {ADD_FIRST, ADD_SECOND, ADD_THIRD, ADD_FORTH, ADD_FIFTH, ADD_SIXTH, ADD_SEVENTH, ADD_EIGHTH,ADD_NINTH, ADD_TEN,
             ADD_ELEVEN, ADD_TWELVE, ADD_THIRTEEN, ADD_FOURTEEN, ADD_FIFTEEN, ADD_SIXTEEN, ADD_SEVENTEEN, ADD_EIGHTEEN,
               REMOVE_THIRD, REMOVE_SEVENTH, REMOVE_SIXTEEN, REMOVE_SEVENTEEN, REMOVE_EIGHTEEN, REMOVE_ELEVEN, REMOVE_CH4, REMOVE_FOURTEEN,
               REMOVE_CH2, REMOVE_FIFTEEN, REMOVE_THIRTEEN, REMOVE_CH5, REMOVE_TEN, REMOVE_CH3, REMOVE_GW2, REMOVE_GW6, REMOVE_GW1,
               REJOIN_ELEVEN, REMOVE_REJOIN_ELEVEN, REJOIN_CH5, REJOIN_GW2, REMOVE_REJOIN_CH5, REMOVE_REJOIN_GW2};

int cnt=0,checkway=0;
bool isSent=false,isSentSec=false;
Status state=ADD_FIRST;

void Node::initialize()
{
    checkway=0;
    if (state==ADD_FIRST && strcmp("newNode", getName()) == 0)
    {
        cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
        sendDirect(new cMessage("ConnectionMsg"),chM, "out",0);
    }
    if (state==ADD_SECOND &&  strcmp("newNode2", getName()) == 0)
    {
        cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
        sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
        cModule *m1 = getParentModule ()-> getSubmodule("Member1");
        sendDirect(new cMessage("ConnectionMsg"),m1, "out",1);
    }
    if (state==ADD_THIRD &&  strcmp("newNode3", getName()) == 0)
    {
        cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
        sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
        cModule *m2 = getParentModule ()-> getSubmodule("Member2");
        sendDirect(new cMessage("ConnectionMsg"),m2, "out",1);
    }
    if (state==ADD_FORTH &&  strcmp("newNode4", getName()) == 0)
    {
        cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
        sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
        cModule *ch1 = getParentModule ()-> getSubmodule("ClusterHead1");
        sendDirect(new cMessage("ConnectionMsg"),ch1, "out",1);
    }
    if (state==ADD_FIFTH &&  strcmp("newNode5", getName()) == 0)
    {
        cModule *ch1 = getParentModule ()-> getSubmodule("ClusterHead1");
        sendDirect(new cMessage("ConnectionMsg"),ch1, "out",1);
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
    }
    if (state==ADD_SIXTH &&  strcmp("newNode6", getName()) == 0)
    {
        cModule *ch1 = getParentModule ()-> getSubmodule("ClusterHead1");
        sendDirect(new cMessage("ConnectionMsg"),ch1, "out",1);
        cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
        sendDirect(new cMessage("ConnectionMsg"),gw2, "out",0);
    }
    if (state==ADD_EIGHTH &&  strcmp("newNode7", getName()) == 0)
    {
        cModule *m1 = getParentModule ()-> getSubmodule("Member1");
        sendDirect(new cMessage("ConnectionMsg"),m1, "out",0);
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
    }
    if (state==REMOVE_THIRD &&  strcmp("Member3", getName()) == 0)
    {
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
    }
    if (state==ADD_NINTH &&  strcmp("newNode8", getName()) == 0)
    {
        cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
        sendDirect(new cMessage("ConnectionMsg"),gw2, "out",0);
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
    }

    if (state==ADD_TEN &&  strcmp("Node10", getName()) == 0)
    {
        cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");
        sendDirect(new cMessage("ConnectionMsg"),gw6, "out",0);
    }
    if (state==ADD_ELEVEN &&  strcmp("Node11", getName()) == 0)
    {
        cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");
        sendDirect(new cMessage("ConnectionMsg"),ch10, "out",0);
    }
    if (state==ADD_TWELVE &&  strcmp("Node12", getName()) == 0)
    {
        cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");
        sendDirect(new cMessage("ConnectionMsg"),ch2, "out",1);
    }
    if (state==ADD_THIRTEEN &&  strcmp("Node13", getName()) == 0)
    {
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
        cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");
        sendDirect(new cMessage("ConnectionMsg"),ch5, "out",0);
    }
    if (state==ADD_FOURTEEN &&  strcmp("Node14", getName()) == 0)
    {
       cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");
       sendDirect(new cMessage("ConnectionMsg"),ch2, "out",1);
    }
    if (state==ADD_FIFTEEN &&  strcmp("Node15", getName()) == 0)
    {
       cModule *ch13 = getParentModule ()-> getSubmodule("ClusterHead13");
       sendDirect(new cMessage("ConnectionMsg"),ch13, "out",1);
    }
    if (state==ADD_SIXTEEN &&  strcmp("Node16", getName()) == 0)
    {
       cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");
       sendDirect(new cMessage("ConnectionMsg"),ch5, "out",1);
    }
    if (state==ADD_SEVENTEEN &&  strcmp("Node17", getName()) == 0)
    {
       cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");
       sendDirect(new cMessage("ConnectionMsg"),ch5, "out",1);
    }
    if (state==ADD_EIGHTEEN &&  strcmp("Node18", getName()) == 0)
    {
        cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");
       sendDirect(new cMessage("ConnectionMsg"),ch2, "out",1);
    }
    if (state==REMOVE_SIXTEEN &&  strcmp("Member16", getName()) == 0)
   {
      cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");
      sendDirect(new cMessage("LeavenMsg"),ch5, "out",1);
   }
    if (state==REMOVE_SEVENTEEN &&  strcmp("Member17", getName()) == 0)
    {
       cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");
       sendDirect(new cMessage("LeaveMsg"),ch5, "out",1);
       eliminateNode("Member16");
    }
    if (state==REMOVE_EIGHTEEN &&  strcmp("Member18", getName()) == 0)
    {
        cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");
       sendDirect(new cMessage("LeaveMsg"),ch2, "out",1);
       eliminateNode("Member17");
    }
    if (state==REMOVE_ELEVEN &&  strcmp("Member11", getName()) == 0)
    {
        cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");
        sendDirect(new cMessage("LeavingMsg"),ch10, "out",0);
        eliminateNode("Member18");
    }
    if (state==REMOVE_CH4 &&  strcmp("ClusterHead4", getName()) == 0)
    {
        cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
        sendDirect(new cMessage("LeavingMsg"),gw2, "out",0);
        eliminateNode("Member11");
    }

    if (state==REJOIN_ELEVEN &&  strcmp("Member11", getName()) == 0)
    {
        cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");
        sendDirect(new cMessage("ConnectionMsg"),ch10, "out",0);
    }

    if (state==REMOVE_FOURTEEN &&  strcmp("Member14", getName()) == 0)
    {
        cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");
        sendDirect(new cMessage("LeavingMsg"),ch2, "out",1);
        eliminateNode("ClusterHead4");

    }
    if (state==REMOVE_CH2 &&  strcmp("ClusterHead2", getName()) == 0)
    {
        cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
        sendDirect(new cMessage("LeavingMsg"),gw2, "out",0);
        eliminateNode("Member14");
    }
    if (state==REMOVE_FIFTEEN &&  strcmp("Member15", getName()) == 0)
    {
       cModule *ch13 = getParentModule ()-> getSubmodule("ClusterHead13");
       sendDirect(new cMessage("LeavingMsg"),ch13, "out",1);
       eliminateNode("Member12");
       eliminateNode("ClusterHead2");
    }
    if (state==REMOVE_REJOIN_ELEVEN &&  strcmp("Member11", getName()) == 0)
    {
        cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");
        sendDirect(new cMessage("LeavingMsg"),ch10, "out",0);
        eliminateNode("Member15");
    }

    if (state==REMOVE_TEN &&  strcmp("ClusterHead10", getName()) == 0)
    {
       cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");
       sendDirect(new cMessage("LeavingMsg"),gw6, "out",0);
       eliminateNode("Member11");
    }
    if (state==REMOVE_CH5 &&  strcmp("ClusterHead5", getName()) == 0)
    {
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("LeavingMsg"),gw1, "out",0);
        eliminateNode("ClusterHead10");
    }
    if (state==REMOVE_CH3 &&  strcmp("ClusterHead3", getName()) == 0)
    {
        cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");
        sendDirect(new cMessage("LeavingMsg"),gw6, "out",0);
        eliminateNode("ClusterHead5");
    }
    if (state==REJOIN_CH5 &&  strcmp("ClusterHead5", getName()) == 0)
    {
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
        eliminateNode("ClusterHead3");
    }

    if (state==REMOVE_THIRTEEN &&  strcmp("ClusterHead13", getName()) == 0)
    {
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("LeavingMsg"),gw1, "out",0);

    }
    if (state==REMOVE_GW2 &&  strcmp("GateWay2", getName()) == 0)
    {
        cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
        sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
        eliminateNode("ClusterHead13");
    }
    if (state==REMOVE_GW6 &&  strcmp("GateWay6", getName()) == 0)
   {
       cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
       sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
       eliminateNode("GateWay2");
   }
    if (state==REJOIN_GW2 &&  strcmp("GateWay2", getName()) == 0)
    {
        cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
        sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
        eliminateNode("GateWay6");
    }
    if (state==REMOVE_REJOIN_CH5 &&  strcmp("ClusterHead5", getName()) == 0)
    {
        cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
        sendDirect(new cMessage("LeavingMsg"),gw1, "out",0);
        //eliminateNode("ClusterHead10");
    }
    if (state==REMOVE_REJOIN_GW2 &&  strcmp("GateWay2", getName()) == 0)
    {
        cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
        sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
        eliminateNode("ClusterHead5");
    }
    if (state==REMOVE_GW1 &&  strcmp("GateWay1", getName()) == 0)
   {
       cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
       sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
       eliminateNode("GateWay2");

   }


}

void Node::handleMessage(cMessage *msg)
{
    hopCountVector.record(GetMessageTime());
    hopCountStats.collect(GetMessageTime());
    recordScalar("#sent", numSent);
    recordScalar("#received", numReceived);
    hopCountStats.recordAs("hop count");
    hopCountVector.record(numSent);

    cModule *bs = getParentModule ()-> getSubmodule("BS");
    cModule *chM = getParentModule ()-> getSubmodule("MainClusterHead");
    cModule *nN = getParentModule ()-> getSubmodule("newNode");
    EV << chM->getProperties()->detailedInfo();

    switch(state)
    {
    case ADD_FIRST:
        if(cnt<4)
        {
            if (strcmp("newNode", getName()) == 0)
            {
                sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
            }
            else if (strcmp("BS", getName()) == 0)
            {
                sendDirect(new cMessage("ConnectionMsg"),chM, "out",0);
            }
            cnt++;
        }
        else
        {
            cGate *outg=nN->gate("out",0);
            outg->setDisplayString("ls=black");
            outg=chM->gate("out",0);
            outg->setDisplayString("ls=black");
            nN->setDisplayString("i=device/accesspoint");
            nN->setName("Member1");

            createNode("newNode2","p=100,281");
            cModule *nn2 = getParentModule ()-> getSubmodule("newNode2");
            cModule *m1 = getParentModule ()-> getSubmodule("Member1");

            chM->setGateSize("in",3);
            chM->setGateSize("out",3);
            m1->setGateSize("in",2);
            m1->setGateSize("out",2);

            nn2->gate("out",0)->connectTo(chM->gate("in",2));
            chM->gate("out",2)->connectTo(nn2->gate("in",0));
            nn2->gate("out",1)->connectTo(m1->gate("in",1));
            m1->gate("out",1)->connectTo(nn2->gate("in",1));

            outg=nn2->gate("out",0);
            outg->setDisplayString("ls=red");
            outg=nn2->gate("out",1);
            outg->setDisplayString("ls=red");
            outg=chM->gate("out",2);
            outg->setDisplayString("ls=red");
            outg=m1->gate("out",1);
            outg->setDisplayString("ls=red");

            state=ADD_SECOND;
            cnt=0;
            nn2->callInitialize();

        }
        break;
    case ADD_SECOND:
        if(cnt<4)
            {
                if (strcmp("newNode2", getName()) == 0)
                {
                    if(!isSent)
                        sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                    isSent=true;
                }
                if (strcmp("BS", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),chM, "out",2);
                }
                cnt++;
            }
            else
            {
                cModule *nn2 = getParentModule ()-> getSubmodule("newNode2");
                cModule *m1 = getParentModule ()-> getSubmodule("Member1");
                cGate *outg=nn2->gate("out",1);

                calDistance("newNode2","Member1");
                outg->disconnect();
                outg=m1->gate("out",1);
                outg->disconnect();

                outg=nn2->gate("out",0);
                outg->setDisplayString("ls=black");
                outg=chM->gate("out",2);
                outg->setDisplayString("ls=black");

                nn2->setDisplayString("i=device/accesspoint");
                nn2->setName("Member2");


                createNode("newNode3","p=269,302");
                cModule *nn3 = getParentModule ()-> getSubmodule("newNode3");
                cModule *m2 = getParentModule ()-> getSubmodule("Member2");

                chM->setGateSize("in",4);
                chM->setGateSize("out",4);
                m2->setGateSize("in",2);
                m2->setGateSize("out",2);

                nn3->gate("out",0)->connectTo(chM->gate("in",3));
                chM->gate("out",3)->connectTo(nn3->gate("in",0));
                nn3->gate("out",1)->connectTo(m2->gate("in",1));
                m2->gate("out",1)->connectTo(nn3->gate("in",1));

                outg=nn3->gate("out",0);
                outg->setDisplayString("ls=red");
                outg=nn3->gate("out",1);
                outg->setDisplayString("ls=red");
                outg=chM->gate("out",3);
                outg->setDisplayString("ls=red");
                outg=m2->gate("out",1);
                outg->setDisplayString("ls=red");

                state=ADD_THIRD;
                cnt=0;
                isSent=false;
                nn3->callInitialize();

            }
        break;
    case ADD_THIRD:
            if(cnt<4)
            {
                if (strcmp("newNode3", getName()) == 0)
                {
                    if(!isSent)
                        sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                    isSent=true;
                }
                if (strcmp("BS", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),chM, "out",3);
                }
                cnt++;
            }
            else
            {
                cModule *nn3 = getParentModule ()-> getSubmodule("newNode3");
                cModule *m2 = getParentModule ()-> getSubmodule("Member2");

                cGate *outg=nn3->gate("out",0);

                calDistance("newNode3","Member2");
                outg->disconnect();
                outg=chM->gate("out",3);
                outg->disconnect();

                outg=nn3->gate("out",1);
                outg->setDisplayString("ls=black");
                outg=m2->gate("out",1);
                outg->setDisplayString("ls=black");

                nn3->setDisplayString("i=block/routing");
                nn3->setName("ClusterHead1");
                m2->setDisplayString("i=device/switch");
                m2->setName("GateWay1");

                createNode("newNode4","p=352,171");
                cModule *nn4 = getParentModule ()-> getSubmodule("newNode4");
                cModule *ch1 = getParentModule ()-> getSubmodule("ClusterHead1");

                chM->setGateSize("in",5);
                chM->setGateSize("out",5);
                ch1->setGateSize("in",3);
                ch1->setGateSize("out",3);

                nn4->gate("out",0)->connectTo(chM->gate("in",4));
                chM->gate("out",4)->connectTo(nn4->gate("in",0));
                nn4->gate("out",1)->connectTo(ch1->gate("in",2));
                ch1->gate("out",2)->connectTo(nn4->gate("in",1));

                outg=nn4->gate("out",0);
                outg->setDisplayString("ls=red");
                outg=nn4->gate("out",1);
                outg->setDisplayString("ls=red");
                outg=chM->gate("out",4);
                outg->setDisplayString("ls=red");
                outg=ch1->gate("out",2);
                outg->setDisplayString("ls=red");

                state=ADD_FORTH;
                cnt=0;
                isSent=false;
                nn4->callInitialize();

            }
            break;
    case ADD_FORTH:
            if(cnt<6)
            {
                if (strcmp("newNode4", getName()) == 0)
                {
                    if(!isSent)
                        sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                    isSent=true;
                }
                if (strcmp("BS", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),chM, "out",4);
                }
                if (strcmp("GateWay1", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                }
                cnt++;
            }
            else
            {
                cModule *nn4 = getParentModule ()-> getSubmodule("newNode4");
                cModule *ch1 = getParentModule ()-> getSubmodule("ClusterHead1");

                cGate *outg=nn4->gate("out",1);

                calDistance("newNode4","ClusterHead1");

                outg->disconnect();
                outg=ch1->gate("out",2);
                outg->disconnect();

                outg=nn4->gate("out",0);
                outg->setDisplayString("ls=black");
                outg=chM->gate("out",4);
                outg->setDisplayString("ls=black");

                nn4->setDisplayString("i=device/switch");
                nn4->setName("GateWay2");

                createNode("newNode5","p=237,420");
                cModule *nn5 = getParentModule ()-> getSubmodule("newNode5");
                cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

                gw1->setGateSize("in",3);
                gw1->setGateSize("out",3);

                nn5->gate("out",0)->connectTo(ch1->gate("in",2));
                ch1->gate("out",2)->connectTo(nn5->gate("in",0));
                nn5->gate("out",1)->connectTo(gw1->gate("in",2));
                gw1->gate("out",2)->connectTo(nn5->gate("in",1));

                outg=nn5->gate("out",0);
                outg->setDisplayString("ls=red");
                outg=nn5->gate("out",1);
                outg->setDisplayString("ls=red");
                outg=gw1->gate("out",2);
                outg->setDisplayString("ls=red");
                outg=ch1->gate("out",2);
                outg->setDisplayString("ls=red");

                state=ADD_FIFTH;
                cnt=0;
                isSent=false;
                nn5->callInitialize();

            }
            break;
       case ADD_FIFTH:
            if(cnt<6)
            {
                cModule *ch1 = getParentModule ()-> getSubmodule("ClusterHead1");
                cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
                cModule *nn5 = getParentModule ()-> getSubmodule("newNode5");
                if (strcmp("newNode5", getName()) == 0)
                {
                        sendDirect(new cMessage("ConnectionMsg"),ch1, "out",1);
                        sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
                }
                if (strcmp("MainClusterHead", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                }
                if (strcmp("GateWay1", getName()) == 0)
                {
                    if(!isSent)
                    {
                       ev<<"in";
                       sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                       isSent=true;
                    }
                    else
                    {
                        sendDirect(new cMessage("ConnectionMsg"),nn5, "out",2);
                        checkway++;
                        if(checkway>=2)
                            isSent=false;
                    }
                }
                if (strcmp("BS", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),chM, "out",2);
                }
                cnt++;
            }
            else
            {
                cancelAndDelete(msg);
                cModule *nn5 = getParentModule ()-> getSubmodule("newNode5");
                cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
                cModule *ch1 = getParentModule ()-> getSubmodule("ClusterHead1");

                cGate *outg=nn5->gate("out",1);
                outg->disconnect();
                outg=gw1->gate("out",2);
                outg->disconnect();

                outg=nn5->gate("out",0);
                outg->setDisplayString("ls=black");
                outg=ch1->gate("out",2);
                outg->setDisplayString("ls=black");

                nn5->setDisplayString("i=device/accesspoint");
                nn5->setName("Member3");

                createNode("newNode6","p=478,276");
                cModule *nn6 = getParentModule ()-> getSubmodule("newNode6");
                cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");

                gw2->setGateSize("in",4);
                gw2->setGateSize("out",4);
                ch1->setGateSize("in",4);
                ch1->setGateSize("out",4);

                nn6->gate("out",0)->connectTo(ch1->gate("in",3));
                ch1->gate("out",3)->connectTo(nn6->gate("in",0));
                nn6->gate("out",1)->connectTo(gw2->gate("in",3));
                gw2->gate("out",3)->connectTo(nn6->gate("in",1));

                outg=nn6->gate("out",0);
                outg->setDisplayString("ls=red");
                outg=nn6->gate("out",1);
                outg->setDisplayString("ls=red");
                outg=gw2->gate("out",3);
                outg->setDisplayString("ls=red");
                outg=ch1->gate("out",3);
                outg->setDisplayString("ls=red");

                state=ADD_SIXTH;
                cnt=0;
                isSent=false;
                nn6->callInitialize();

            }
            break;
       case ADD_SIXTH:
           if(cnt<12)
           {
               cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
               cModule *nn6 = getParentModule ()-> getSubmodule("newNode6");
               if (strcmp("newNode6", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                   sendDirect(new cMessage("ConnectionMsg"),gw2, "out",0);
               }
               if (strcmp("MainClusterHead", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
               }
               if (strcmp("GateWay1", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
               }
               if (strcmp("BS", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",4);
               }
               if (strcmp("GateWay2", getName()) == 0)
               {
                   if(cnt<2 || (cnt>4 && cnt<6) || (cnt>7 && cnt<12) || cnt>14)
                   {
                       sendDirect(new cMessage("ConnectionMsg"),nn6, "out",1);
                       //isSent=true;
                   }
                   else
                   {
                       sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                   }
               }
               cnt++;
           }
           else
           {
               cancelAndDelete(msg);
               cModule *nn6 = getParentModule ()-> getSubmodule("newNode6");
               cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
               cModule *ch1 = getParentModule ()-> getSubmodule("ClusterHead1");

               cGate *outg=nn6->gate("out",0);
               outg->disconnect();
               outg=ch1->gate("out",3);
               outg->disconnect();

               outg=nn6->gate("out",1);
               outg->setDisplayString("ls=black");
               outg=gw2->gate("out",3);
               outg->setDisplayString("ls=black");

               nn6->setDisplayString("i=block/routing");
               nn6->setName("ClusterHead2");

               createNode("newNode7","p=43,146");
               cModule *nn7 = getParentModule ()-> getSubmodule("newNode7");
               cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
               cModule *m1 = getParentModule ()-> getSubmodule("Member1");

               gw1->setGateSize("in",4);
               gw1->setGateSize("out",4);
               m1->setGateSize("in",3);
               m1->setGateSize("out",3);

               nn7->gate("out",0)->connectTo(m1->gate("in",1));
               m1->gate("out",1)->connectTo(nn7->gate("in",0));
               nn7->gate("out",1)->connectTo(gw1->gate("in",2));
               gw1->gate("out",2)->connectTo(nn7->gate("in",1));

               outg=nn7->gate("out",0);
               outg->setDisplayString("ls=red");
               outg=nn7->gate("out",1);
               outg->setDisplayString("ls=red");
               outg=gw1->gate("out",2);
               outg->setDisplayString("ls=red");
               outg=m1->gate("out",1);
               outg->setDisplayString("ls=red");

               state=ADD_EIGHTH;
               cnt=0;
               isSent=false;
               nn7->callInitialize();

           }
           break;
       case ADD_EIGHTH:
          if(cnt<12)
          {
              cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
              cModule *nn7 = getParentModule ()-> getSubmodule("newNode7");
              cModule *m1 = getParentModule ()-> getSubmodule("Member1");
              if (strcmp("newNode7", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),m1, "out",0);
                  sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
              }
              if (strcmp("MainClusterHead", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",0);
              }
              if (strcmp("Member1", getName()) == 0)
              {
                  if(cnt<6 || cnt>8)
                      sendDirect(new cMessage("ConnectionMsg"),nn7, "out",0);
                  else
                      sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
              }
              cnt++;
          }
          else
          {
              cancelAndDelete(msg);
              cModule *nn7 = getParentModule ()-> getSubmodule("newNode7");
              cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
              cModule *m1 = getParentModule ()-> getSubmodule("Member1");

              cGate *outg=nn7->gate("out",1);
              outg->disconnect();
              outg=gw1->gate("out",2);
              outg->disconnect();

              outg=nn7->gate("out",0);
              outg->setDisplayString("ls=black");
              outg=m1->gate("out",1);
              outg->setDisplayString("ls=black");

              nn7->setDisplayString("i=block/routing");
              nn7->setName("ClusterHead3");
              m1->setDisplayString("i=device/switch");
              m1->setName("GateWay6");

              //createNode("newNode7","p=43,146");
              eliminateNode("ClusterHead1");
              eliminateNode("Member3");
              createNode("Member3","p=237,420");

              cModule *m3 = getParentModule ()-> getSubmodule("Member3");

              gw1->gate("out",3)->connectTo(m3->gate("in",1));
              m3->gate("out",1)->connectTo(gw1->gate("in",3));

              outg=gw1->gate("out",3);
              outg->setDisplayString("ls=red");
              outg=m3->gate("out",1);
              outg->setDisplayString("ls=red");

              state=REMOVE_THIRD;
              cnt=0;
              isSent=false;
              m3->callInitialize();

          }
          break;
       case REMOVE_THIRD:
           if(cnt<7)
           {
               cModule *m3 = getParentModule ()-> getSubmodule("Member3");
               cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

               if (strcmp("Member3", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
               }
               if (strcmp("MainClusterHead", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
               }
               if (strcmp("GateWay1", getName()) == 0)
               {
                   if(cnt<4 || cnt>5 )
                       sendDirect(new cMessage("ConnectionMsg"),m3, "out",1);
                   else
                       sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
               }
               if (strcmp("BS", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",2);
               }
               cnt++;
           }
           else
           {
               cancelAndDelete(msg);
               cModule *m3 = getParentModule ()-> getSubmodule("Member3");
               cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

               cGate *outg=m3->gate("out",1);
               outg->setDisplayString("ls=black");
               outg=gw1->gate("out",3);
               outg->setDisplayString("ls=black");

               m3->setDisplayString("i=block/routing");
               m3->setName("ClusterHead5");

               createNode("newNode8","p=278,276");
               cModule *nn8 = getParentModule ()-> getSubmodule("newNode8");
               cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");

               gw2->setGateSize("in",4);
               gw2->setGateSize("out",4);
               gw1->setGateSize("in",4);
               gw1->setGateSize("out",4);

               nn8->gate("out",0)->connectTo(gw2->gate("in",2));
               gw2->gate("out",2)->connectTo(nn8->gate("in",0));
               nn8->gate("out",1)->connectTo(gw1->gate("in",2));
               gw1->gate("out",2)->connectTo(nn8->gate("in",1));

               outg=nn8->gate("out",0);
               outg->setDisplayString("ls=red");
               outg=nn8->gate("out",1);
               outg->setDisplayString("ls=red");
               outg=gw2->gate("out",2);
               outg->setDisplayString("ls=red");
               outg=gw1->gate("out",2);
               outg->setDisplayString("ls=red");

               state=ADD_NINTH;
               cnt=0;
               isSent=false;
               nn8->callInitialize();

           }
           break;
       case ADD_NINTH:
         if(cnt<13)
         {
             cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
             cModule *nn8 = getParentModule ()-> getSubmodule("newNode8");
             if (strcmp("newNode8", getName()) == 0)
             {
                 sendDirect(new cMessage("ConnectionMsg"),gw2, "out",0);
                 //sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
             }
             if (strcmp("MainClusterHead", getName()) == 0)
             {
                 sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
             }
             if (strcmp("GateWay2", getName()) == 0)
             {
                 if(cnt>3 || cnt>10)
                     sendDirect(new cMessage("ConnectionMsg"),nn8, "out",2);
                 else
                     sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
             }
             if (strcmp("BS", getName()) == 0)
             {
                 sendDirect(new cMessage("ConnectionMsg"),chM, "out",4);
             }

             cnt++;
         }
         else
         {
            cancelAndDelete(msg);
            cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");
            cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
            cModule *nn8 = getParentModule ()-> getSubmodule("newNode8");

            cGate *outg=nn8->gate("out",1);
            outg->disconnect();
            outg=gw1->gate("out",2);
            outg->disconnect();

            outg=nn8->gate("out",0);
            outg->setDisplayString("ls=black");
            outg=gw2->gate("out",2);
            outg->setDisplayString("ls=black");

            nn8->setDisplayString("i=block/routing");
            nn8->setName("ClusterHead4");

               createNode("Node10","p=80,60");
               cModule *n10 = getParentModule ()-> getSubmodule("Node10");
               cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");



               gw6->setGateSize("in",5);
               gw6->setGateSize("out",5);

               n10->gate("out",0)->connectTo(gw6->gate("in",4));
               gw6->gate("out",4)->connectTo(n10->gate("in",0));

               outg=n10->gate("out",0);
               outg->setDisplayString("ls=red");
               outg=gw6->gate("out",4);
               outg->setDisplayString("ls=red");

               state=ADD_TEN;
               cnt=0;
               isSent=false;
               n10->callInitialize();

           }
           break;
       case ADD_TEN:
           if(cnt<5)
           {
               cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");
               if (strcmp("MainClusterHead", getName()) == 0)
               {
                   if(!isSent)
                   {
                       sendDirect(new cMessage("ConnectionMsg"),bs, "out",0);
                       isSent=true;
                   }
                   else
                   {
                       sendDirect(new cMessage("ConnectionMsg"),gw6, "out",4);
                       isSent=false;
                   }
               }
               if (strcmp("Node10", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),gw6, "out",0);
               }
               if (strcmp("GateWay6", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),gw6, "out",0);
               }
               cnt++;
           }
           else
           {
               cModule *n10 = getParentModule ()-> getSubmodule("Node10");
               cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");


               cGate *outg=n10->gate("out",0);
               outg->setDisplayString("ls=black");
               outg=gw6->gate("out",4);
               outg->setDisplayString("ls=black");

               n10->setDisplayString("i=block/routing");
               n10->setName("ClusterHead10");

               cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");
              cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");

              outg=ch2->gate("out",2);
              outg->disconnect();

             /* outg=gw2->gate("out",4);
              outg->disconnect();*/


               createNode("Node11","p=180,60");
               cModule *n11 = getParentModule ()-> getSubmodule("Node11");
               cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");

               n11->gate("out",0)->connectTo(ch10->gate("in",1));
               ch10->gate("out",1)->connectTo(n11->gate("in",0));

               outg=n11->gate("out",0);
               outg->setDisplayString("ls=red");
               outg=ch10->gate("out",1);
               outg->setDisplayString("ls=red");

               state=ADD_ELEVEN;
               cnt=0;
               isSent=false;
               n11->callInitialize();

           }
           break;
       case ADD_ELEVEN:
          if(cnt<7)
          {
              cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");
              if (strcmp("Node11", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),ch10, "out",0);
              }
              if (strcmp("GateWay6", getName()) == 0)
              {
                  if(!isSent)
                  {
                      sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                      isSent=true;
                  }
                  else
                  {
                      sendDirect(new cMessage("ConnectionMsg"),ch10, "out",1);
                      isSent=false;
                  }
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",0);
              }

              cnt++;
          }
          else
          {
              cModule *n11 = getParentModule ()-> getSubmodule("Node11");
              cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");


              cGate *outg=n11->gate("out",0);
              outg->setDisplayString("ls=black");
              outg=ch10->gate("out",1);
              outg->setDisplayString("ls=black");

              n11->setDisplayString("i=device/accesspoint");
              n11->setName("Member11");

               createNode("Node12","p=568,276");
              cModule *n12 = getParentModule ()-> getSubmodule("Node12");
               cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

               ch2->setGateSize("in",3);
               ch2->setGateSize("out",3);

               n12->gate("out",0)->connectTo(ch2->gate("in",2));
               ch2->gate("out",2)->connectTo(n12->gate("in",0));

               outg=n12->gate("out",0);
               outg->setDisplayString("ls=red");
               outg=ch2->gate("out",2);
               outg->setDisplayString("ls=red");


              state=ADD_TWELVE;
              cnt=0;
              isSent=false;
              n12->callInitialize();

          }
          break;
       case ADD_TWELVE:
         if(cnt<7)
         {
             cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

             if (strcmp("GateWay2", getName()) == 0)
             {
                 if(!isSent)
                 {
                     sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                     isSent=true;
                 }
                 else
                 {
                     sendDirect(new cMessage("ConnectionMsg"),ch2, "out",2);
                     isSent=false;
                 }
             }
             if (strcmp("BS", getName()) == 0)
             {
                 sendDirect(new cMessage("ConnectionMsg"),chM, "out",4);
             }
             if (strcmp("Node12", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),ch2, "out",1);
              }
             cnt++;
         }
         else
         {
             cModule *n12 = getParentModule ()-> getSubmodule("Node12");
             cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");


             cGate *outg=n12->gate("out",0);
             outg->setDisplayString("ls=black");
             outg=ch2->gate("out",2);
             outg->setDisplayString("ls=black");

             n12->setDisplayString("i=device/accesspoint");
             n12->setName("Member12");


             createNode("Node13","p=80,416");
             cModule *n13 = getParentModule ()-> getSubmodule("Node13");
             cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");
             cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

             ch5->setGateSize("in",3);
             ch5->setGateSize("out",3);
             gw1->setGateSize("in",5);
             gw1->setGateSize("out",5);

             n13->gate("out",0)->connectTo(ch5->gate("in",2));
             ch5->gate("out",2)->connectTo(n13->gate("in",0));
             n13->gate("out",1)->connectTo(gw1->gate("in",4));
             gw1->gate("out",4)->connectTo(n13->gate("in",1));

             outg=n13->gate("out",0);
             outg->setDisplayString("ls=red");
             outg=ch5->gate("out",2);
             outg->setDisplayString("ls=red");
             outg=n13->gate("out",1);
              outg->setDisplayString("ls=red");
              outg=gw1->gate("out",4);
              outg->setDisplayString("ls=red");

             state=ADD_THIRTEEN;
             cnt=0;
             isSent=false;
             n13->callInitialize();

         }
         break;
       case ADD_THIRTEEN:
            if(cnt<9)
            {
                cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

                if (strcmp("MainClusterHead", getName()) == 0)
                {
                    if(!isSent)
                    {
                        sendDirect(new cMessage("ConnectionMsg"),bs, "out",0);
                        isSent=true;
                    }
                    else
                    {
                        sendDirect(new cMessage("ConnectionMsg"),gw1, "out",4);
                        isSent=false;
                    }
                }

                if (strcmp("Node13", getName()) == 0)
                 {
                     sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
                 }
                cnt++;
            }
            else
            {
                cModule *n13 = getParentModule ()-> getSubmodule("Node13");
                cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");
                cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");


              cGate *outg=n13->gate("out",1);
              outg->setDisplayString("ls=black");
              outg=gw1->gate("out",4);
              outg->setDisplayString("ls=black");

              n13->setDisplayString("i=block/routing");
              n13->setName("ClusterHead13");

              outg= n13->gate("out",0);
              outg->disconnect();
              outg=ch5->gate("out",2);
              outg->disconnect();

              createNode("Node14","p=568,376");
              cModule *n14 = getParentModule ()-> getSubmodule("Node14");
               cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

               ch2->setGateSize("in",4);
               ch2->setGateSize("out",4);

               n14->gate("out",0)->connectTo(ch2->gate("in",3));
               ch2->gate("out",3)->connectTo(n14->gate("in",0));

               outg=n14->gate("out",0);
               outg->setDisplayString("ls=red");
               outg=ch2->gate("out",3);
               outg->setDisplayString("ls=red");


              state=ADD_FOURTEEN;
              cnt=0;
              isSent=false;
              n14->callInitialize();
            }
            break;
       case ADD_FOURTEEN:
           if(cnt<7)
            {
                cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

                if (strcmp("GateWay2", getName()) == 0)
                {
                    if(!isSent)
                    {
                        sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                        isSent=true;
                    }
                    else
                    {
                        sendDirect(new cMessage("ConnectionMsg"),ch2, "out",3);
                        isSent=false;
                    }
                }
                if (strcmp("BS", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),chM, "out",4);
                }
                if (strcmp("Node14", getName()) == 0)
                 {
                     sendDirect(new cMessage("ConnectionMsg"),ch2, "out",1);
                 }
                cnt++;
            }
            else
            {
                cModule *n14 = getParentModule ()-> getSubmodule("Node14");
                cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");


                cGate *outg=n14->gate("out",0);
                outg->setDisplayString("ls=black");
                outg=ch2->gate("out",3);
                outg->setDisplayString("ls=black");

                n14->setDisplayString("i=device/accesspoint");
                n14->setName("Member14");


                createNode("Node15","p=70,496");
                cModule *n15 = getParentModule ()-> getSubmodule("Node15");
                cModule *ch13 = getParentModule ()-> getSubmodule("ClusterHead13");

                ch13->setGateSize("in",3);
                ch13->setGateSize("out",3);

                n15->gate("out",0)->connectTo(ch13->gate("in",2));
                ch13->gate("out",2)->connectTo(n15->gate("in",0));

                outg=n15->gate("out",0);
                outg->setDisplayString("ls=red");
                outg=ch13->gate("out",2);
                outg->setDisplayString("ls=red");

                state=ADD_FIFTEEN;
                cnt=0;
                isSent=false;
                n15->callInitialize();
            }
           break;
       case ADD_FIFTEEN:
          if(cnt<7)
           {
               cModule *ch13 = getParentModule ()-> getSubmodule("ClusterHead13");

               if (strcmp("GateWay1", getName()) == 0)
               {
                   if(!isSent)
                   {
                       sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                       isSent=true;
                   }
                   else
                   {
                       sendDirect(new cMessage("ConnectionMsg"),ch13, "out",2);
                       isSent=false;
                   }
               }
               if (strcmp("BS", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",2);
               }
               if (strcmp("Node15", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),ch13, "out",1);
                }
               cnt++;
           }
           else
           {
               cModule *n15 = getParentModule ()-> getSubmodule("Node15");
               cModule *ch13 = getParentModule ()-> getSubmodule("ClusterHead13");


               cGate *outg=n15->gate("out",0);
               outg->setDisplayString("ls=black");
               outg=ch13->gate("out",2);
               outg->setDisplayString("ls=black");

               n15->setDisplayString("i=device/accesspoint");
               n15->setName("Member15");


               createNode("Node16","p=270,516");
               cModule *n16 = getParentModule ()-> getSubmodule("Node16");
               cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");

               ch5->setGateSize("in",3);
               ch5->setGateSize("out",3);

               n16->gate("out",0)->connectTo(ch5->gate("in",2));
               ch5->gate("out",2)->connectTo(n16->gate("in",0));

               outg=n16->gate("out",0);
               outg->setDisplayString("ls=red");
               outg=ch5->gate("out",2);
               outg->setDisplayString("ls=red");

               state=ADD_SIXTEEN;
               cnt=0;
               isSent=false;
               n16->callInitialize();
           }
          break;
       case ADD_SIXTEEN:
         if(cnt<7)
          {
              cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");

              if (strcmp("GateWay1", getName()) == 0)
              {
                  if(!isSent)
                  {
                      sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                      isSent=true;
                  }
                  else
                  {
                      sendDirect(new cMessage("ConnectionMsg"),ch5, "out",2);
                      isSent=false;
                  }
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",2);
              }
              if (strcmp("Node16", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),ch5, "out",1);
              }
              cnt++;
          }
          else
          {
              cModule *n16 = getParentModule ()-> getSubmodule("Node16");
              cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");

              cGate *outg=n16->gate("out",0);
              outg->setDisplayString("ls=black");
              outg=ch5->gate("out",2);
              outg->setDisplayString("ls=black");

              n16->setDisplayString("i=device/accesspoint");
              n16->setName("Member16");


              createNode("Node17","p=370,516");
              cModule *n17 = getParentModule ()-> getSubmodule("Node17");

              ch5->setGateSize("in",4);
              ch5->setGateSize("out",4);

              n17->gate("out",0)->connectTo(ch5->gate("in",3));
              ch5->gate("out",3)->connectTo(n17->gate("in",0));

              outg=n17->gate("out",0);
              outg->setDisplayString("ls=red");
              outg=ch5->gate("out",3);
              outg->setDisplayString("ls=red");

              state=ADD_SEVENTEEN;
              cnt=0;
              isSent=false;
              n17->callInitialize();
          }
         break;
       case ADD_SEVENTEEN:
        if(cnt<7)
         {
             cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");

             if (strcmp("GateWay1", getName()) == 0)
             {
                 if(!isSent)
                 {
                     sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                     isSent=true;
                 }
                 else
                 {
                     sendDirect(new cMessage("ConnectionMsg"),ch5, "out",3);
                     isSent=false;
                 }
             }
             if (strcmp("BS", getName()) == 0)
             {
                 sendDirect(new cMessage("ConnectionMsg"),chM, "out",2);
             }
             if (strcmp("Node17", getName()) == 0)
             {
                 sendDirect(new cMessage("ConnectionMsg"),ch5, "out",1);
             }
             cnt++;
         }
         else
         {
             cModule *n17 = getParentModule ()-> getSubmodule("Node17");
             cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");

             cGate *outg=n17->gate("out",0);
             outg->setDisplayString("ls=black");
             outg=ch5->gate("out",3);
             outg->setDisplayString("ls=black");

             n17->setDisplayString("i=device/accesspoint");
             n17->setName("Member17");


             createNode("Node18","p=470,456");
            cModule *n18 = getParentModule ()-> getSubmodule("Node18");
            cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

            ch2->setGateSize("in",5);
            ch2->setGateSize("out",5);

            n18->gate("out",0)->connectTo(ch2->gate("in",4));
            ch2->gate("out",4)->connectTo(n18->gate("in",0));

            outg=n18->gate("out",0);
            outg->setDisplayString("ls=red");
            outg=ch2->gate("out",4);
            outg->setDisplayString("ls=red");


           state=ADD_EIGHTEEN;
           cnt=0;
           isSent=false;
           n18->callInitialize();
         }
        break;
       case ADD_EIGHTEEN:
          if(cnt<7)
           {
               cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

               if (strcmp("GateWay2", getName()) == 0)
               {
                   if(!isSent)
                   {
                       sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                       isSent=true;
                   }
                   else
                   {
                       sendDirect(new cMessage("ConnectionMsg"),ch2, "out",4);
                       isSent=false;
                   }
               }
               if (strcmp("BS", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",4);
               }
               if (strcmp("Node18", getName()) == 0)
                {
                    sendDirect(new cMessage("ConnectionMsg"),ch2, "out",1);
                }
               cnt++;
           }
           else
           {
               cModule *n18 = getParentModule ()-> getSubmodule("Node18");
               cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");


               cGate *outg=n18->gate("out",0);
               outg->setDisplayString("ls=black");
               outg=ch2->gate("out",4);
               outg->setDisplayString("ls=black");

               n18->setDisplayString("i=device/accesspoint");
               n18->setName("Member18");

               eliminateNode("Member16");
               createNode("Member16","p=270,516");

               cModule *n16 = getParentModule ()-> getSubmodule("Member16");
               cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");

               n16->setDisplayString("i=device/accesspoint");
               ch5->setGateSize("in",6);
               ch5->setGateSize("out",6);

               n16->gate("out",0)->connectTo(ch5->gate("in",5));
               ch5->gate("out",5)->connectTo(n16->gate("in",0));

               state=REMOVE_SIXTEEN;
               cnt=0;
               isSent=false;
               n16->callInitialize();
           }
          break;
       case REMOVE_SIXTEEN:

           if(cnt<3)
             {
                 cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");

                 if (strcmp("GateWay1", getName()) == 0)
                 {
                     if(!isSent)
                     {
                         sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                         isSent=true;
                     }
                     else
                     {
                         sendDirect(new cMessage("LeavingMsg"),ch5, "out",5);
                         isSent=false;
                     }
                 }
                 if (strcmp("BS", getName()) == 0)
                 {
                     sendDirect(new cMessage("LeavingMsg"),chM, "out",2);
                 }
                 if (strcmp("Member16", getName()) == 0)
                 {
                     sendDirect(new cMessage("LeavingMsg"),ch5, "out",1);
                 }
                 cnt++;
             }
             else
             {
                 eliminateNode("Member17");

                 createNode("Member17","p=370,516");

                 cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");

                 cModule *n17 = getParentModule ()-> getSubmodule("Member17");
                 n17->setDisplayString("i=device/accesspoint");

                 ch5->setGateSize("in",7);
                 ch5->setGateSize("out",7);

                 n17->gate("out",0)->connectTo(ch5->gate("in",6));
                 ch5->gate("out",6)->connectTo(n17->gate("in",0));

                state=REMOVE_SEVENTEEN;
                cnt=0;
                isSent=false;
                n17->callInitialize();
             }
         break;
       case REMOVE_SEVENTEEN:
          if(cnt<3)
            {
              cModule *ch5 = getParentModule ()-> getSubmodule("ClusterHead5");
               if (strcmp("GateWay1", getName()) == 0)
               {
                   if(!isSent)
                   {
                       sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                       isSent=true;
                   }
                   else
                   {
                       sendDirect(new cMessage("LeavingMsg"),ch5, "out",6);
                       isSent=false;
                   }
               }
               if (strcmp("BS", getName()) == 0)
               {
                   sendDirect(new cMessage("LeavingMsg"),chM, "out",2);
               }
               if (strcmp("Member17", getName()) == 0)
               {
                   sendDirect(new cMessage("LeavingMsg"),ch5, "out",1);
               }
               cnt++;
            }
            else
            {

                eliminateNode("Member18");
                createNode("Member18","p=370,516");

                cModule *n18 = getParentModule ()-> getSubmodule("Member18");
                cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

                ch2->setGateSize("in",8);
                ch2->setGateSize("out",8);

                n18->gate("out",0)->connectTo(ch2->gate("in",7));
                ch2->gate("out",7)->connectTo(n18->gate("in",0));
                n18->setDisplayString("i=device/accesspoint");
                //eliminateNode("Member16");

               state=REMOVE_EIGHTEEN;
               cnt=0;
               isSent=false;
               n18->callInitialize();
            }
        break;
       case REMOVE_EIGHTEEN:
           if(cnt<3)
              {
               cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

              if (strcmp("GateWay2", getName()) == 0)
              {
                  if(!isSent)
                  {
                      sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                      isSent=true;
                  }
                  else
                  {
                      sendDirect(new cMessage("LeavingMsg"),ch2, "out",7);
                      isSent=false;
                  }
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",4);
              }
              if (strcmp("Member18", getName()) == 0)
               {
                   sendDirect(new cMessage("LeavingMsg"),ch2, "out",1);
               }
              cnt++;
              }

           else
           {
               eliminateNode("Member11");
               createNode("Member11","p=180,60");
              cModule *n11 = getParentModule ()-> getSubmodule("Member11");
              cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");

              n11->gate("out",0)->connectTo(ch10->gate("in",2));
              ch10->gate("out",2)->connectTo(n11->gate("in",0));

              state=REMOVE_ELEVEN;
              cnt=0;
              isSent=false;
              n11->callInitialize();
           }
       break;
       case REMOVE_ELEVEN:
         if(cnt<3)
         {
             cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");
             if (strcmp("Member11", getName()) == 0)
             {
                 sendDirect(new cMessage("LeavingMsg"),ch10, "out",0);
             }
             if (strcmp("GateWay6", getName()) == 0)
             {
                 if(!isSent)
                 {
                     sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                     isSent=true;
                 }
                 else
                 {
                     sendDirect(new cMessage("LeavingMsg"),ch10, "out",2);
                     isSent=false;
                 }
             }
             if (strcmp("BS", getName()) == 0)
             {
                 sendDirect(new cMessage("LeavingMsg"),chM, "out",0);
             }

             cnt++;
         }
         else
         {
            eliminateNode("ClusterHead4");
            createNode("ClusterHead4","p=278,276");
            cModule *ch4 = getParentModule ()-> getSubmodule("ClusterHead4");
            cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");

            gw2->setGateSize("in",5);
            gw2->setGateSize("out",5);

            ch4->gate("out",0)->connectTo(gw2->gate("in",4));
            gw2->gate("out",4)->connectTo(ch4->gate("in",0));

            state=REMOVE_CH4;
            cnt=0;
            isSent=false;
            ch4->callInitialize();

         }
         break;
       case REMOVE_CH4:
           if(cnt<3)
           {
                cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
                cModule *ch4 = getParentModule ()-> getSubmodule("ClusterHead4");

                if (strcmp("ClusterHead4", getName()) == 0)
                {
                    sendDirect(new cMessage("LeavingMsg"),gw2, "out",0);
                }
                if (strcmp("MainClusterHead", getName()) == 0)
                {
                    if(cnt<2)
                        sendDirect(new cMessage("LeavingMsg"),bs, "out",0);
                    else
                        sendDirect(new cMessage("LeavingMsg"),gw2, "out",4);
                }
                if (strcmp("GateWay2", getName()) == 0)
                {
                    if(cnt>3 || cnt>10)
                        sendDirect(new cMessage("LeavingMsg"),ch4, "out",2);
                    else
                        sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                }
                if (strcmp("BS", getName()) == 0)
                {
                    sendDirect(new cMessage("LeavingMsg"),chM, "out",4);
                }

                cnt++;
           }
           else
           {

                createNode("Member11","p=180,60");
                cModule *n11 = getParentModule ()-> getSubmodule("Member11");
                cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");

                n11->gate("out",0)->connectTo(ch10->gate("in",1));
                ch10->gate("out",1)->connectTo(n11->gate("in",0));

                cGate *outg=n11->gate("out",0);
                outg->setDisplayString("ls=red");
                outg=ch10->gate("out",1);
                outg->setDisplayString("ls=red");

                state=REJOIN_ELEVEN;
                cnt=0;
                isSent=false;
                n11->callInitialize();

           }
           break;


       case REJOIN_ELEVEN:
          if(cnt<7)
          {
              cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");
              if (strcmp("Member11", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),ch10, "out",0);
              }
              if (strcmp("GateWay6", getName()) == 0)
              {
                  if(!isSent)
                  {
                      sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                      isSent=true;
                  }
                  else
                  {
                      sendDirect(new cMessage("ConnectionMsg"),ch10, "out",1);
                      isSent=false;
                  }
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",0);
              }

              cnt++;
          }
          else
          {

              cModule *n11 = getParentModule ()-> getSubmodule("Member11");
                cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");


                cGate *outg=n11->gate("out",0);
                outg->setDisplayString("ls=black");
                outg=ch10->gate("out",1);
                outg->setDisplayString("ls=black");

                n11->setDisplayString("i=device/accesspoint");


              eliminateNode("Member14");
             createNode("Member14","p=568,376");
             cModule *n14 = getParentModule ()-> getSubmodule("Member14");
             cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

             ch2->setGateSize("in",4);
             ch2->setGateSize("out",4);

             n14->gate("out",0)->connectTo(ch2->gate("in",3));
             ch2->gate("out",3)->connectTo(n14->gate("in",0));

             state=REMOVE_FOURTEEN;
             cnt=0;
             isSent=false;
             n14->callInitialize();

          }
          break;




       case REMOVE_FOURTEEN:
          if(cnt<3)
           {
               cModule *ch2 = getParentModule ()-> getSubmodule("ClusterHead2");

               if (strcmp("GateWay2", getName()) == 0)
               {
                   if(!isSent)
                   {
                       sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                       isSent=true;
                   }
                   else
                   {
                       sendDirect(new cMessage("LeavingMsg"),ch2, "out",3);
                       isSent=false;
                   }
               }
               if (strcmp("BS", getName()) == 0)
               {
                   sendDirect(new cMessage("LeavingMsg"),chM, "out",4);
               }
               if (strcmp("Member14", getName()) == 0)
                {
                    sendDirect(new cMessage("LeavingMsg"),ch2, "out",1);
                }
               cnt++;
           }
           else
           {
               eliminateNode("ClusterHead2");
               createNode("ClusterHead2","p=478,276");

               cModule *nn6 = getParentModule ()-> getSubmodule("ClusterHead2");
               cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
               nn6->setDisplayString("i=block/routing");
               gw2->setGateSize("in",5);
               gw2->setGateSize("out",5);

               nn6->gate("out",1)->connectTo(gw2->gate("in",4));
               gw2->gate("out",4)->connectTo(nn6->gate("in",1));

               state=REMOVE_CH2;
               cnt=0;
               isSent=false;
               nn6->callInitialize();
           }
          break;
       case REMOVE_CH2:
          if(cnt<3)
          {
              cModule *gw2 = getParentModule ()-> getSubmodule("GateWay2");
              cModule *nn6 = getParentModule ()-> getSubmodule("ClusterHead2");
              if (strcmp("ClusterHead2", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                  sendDirect(new cMessage("LeavingMsg"),gw2, "out",0);
              }
              if (strcmp("MainClusterHead", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
              }
              if (strcmp("GateWay1", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",4);
              }
              if (strcmp("GateWay2", getName()) == 0)
              {
                  if(cnt<2 || (cnt>4 && cnt<6) || (cnt>7 && cnt<12) || cnt>14)
                  {
                      sendDirect(new cMessage("LeavingMsg"),nn6, "out",1);
                      //isSent=true;
                  }
                  else
                  {
                      sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                  }
              }
              cnt++;
          }
          else
          {
              eliminateNode("Member15");
              createNode("Member15","p=70,496");
              cModule *n15 = getParentModule ()-> getSubmodule("Member15");
              cModule *ch13 = getParentModule ()-> getSubmodule("ClusterHead13");

              ch13->setGateSize("in",4);
              ch13->setGateSize("out",4);

              n15->gate("out",0)->connectTo(ch13->gate("in",3));
              ch13->gate("out",3)->connectTo(n15->gate("in",0));

              state=REMOVE_FIFTEEN;
              cnt=0;
              isSent=false;
              n15->callInitialize();
          }
          break;
       case REMOVE_FIFTEEN:
         if(cnt<3)
          {
              cModule *ch13 = getParentModule ()-> getSubmodule("ClusterHead13");

              if (strcmp("GateWay1", getName()) == 0)
              {
                  if(!isSent)
                  {
                      sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                      isSent=true;
                  }
                  else
                  {
                      sendDirect(new cMessage("LeavingMsg"),ch13, "out",3);
                      isSent=false;
                  }
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",2);
              }
              if (strcmp("Member15", getName()) == 0)
               {
                   sendDirect(new cMessage("LeavingMsg"),ch13, "out",1);
               }
              cnt++;
          }


         else
            {
                eliminateNode("Member11");
                createNode("Member11","p=180,60");
               cModule *n11 = getParentModule ()-> getSubmodule("Member11");
               cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");

               n11->gate("out",0)->connectTo(ch10->gate("in",2));
               ch10->gate("out",2)->connectTo(n11->gate("in",0));

               cGate *outg=n11->gate("out",0);
               outg->setDisplayString("ls=black");
               outg=ch10->gate("out",1);
               outg->setDisplayString("ls=black");

               n11->setDisplayString("i=device/accesspoint");


               state=REMOVE_REJOIN_ELEVEN;
               cnt=0;
               isSent=false;
               n11->callInitialize();
            }
        break;
        case REMOVE_REJOIN_ELEVEN:
          if(cnt<3)
          {
              cModule *ch10 = getParentModule ()-> getSubmodule("ClusterHead10");
              if (strcmp("Member11", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),ch10, "out",0);
              }
              if (strcmp("GateWay6", getName()) == 0)
              {
                  if(!isSent)
                  {
                      sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                      isSent=true;
                  }
                  else
                  {
                      sendDirect(new cMessage("LeavingMsg"),ch10, "out",2);
                      isSent=false;
                  }
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",0);
              }

              cnt++;
          }
          else
          {

              eliminateNode("ClusterHead10");
                createNode("ClusterHead10","p=80,60");
                cModule *n10 = getParentModule ()-> getSubmodule("ClusterHead10");
                cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");

                gw6->setGateSize("in",6);
                gw6->setGateSize("out",6);

                n10->gate("out",0)->connectTo(gw6->gate("in",5));
                gw6->gate("out",5)->connectTo(n10->gate("in",0));

                state=REMOVE_TEN;
                cnt=0;
                isSent=false;
                n10->callInitialize();

          }
         break;
       case REMOVE_TEN:
          if(cnt<2)
          {
              cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");
              if (strcmp("MainClusterHead", getName()) == 0)
              {
                  if(!isSent)
                  {
                      sendDirect(new cMessage("LeavingMsg"),bs, "out",0);
                      isSent=true;
                  }
                  else
                  {
                      sendDirect(new cMessage("LeavingMsg"),gw6, "out",5);
                      isSent=false;
                  }
              }
              if (strcmp("ClusterHead10", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),gw6, "out",0);
              }
              if (strcmp("GateWay6", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),gw6, "out",0);
              }
              cnt++;
          }
          else
          {
              eliminateNode("ClusterHead5");

              createNode("ClusterHead5","p=237,420");

              cModule *m3 = getParentModule ()-> getSubmodule("ClusterHead5");
              cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

              gw1->setGateSize("in",6);
              gw1->setGateSize("out",6);

              gw1->gate("out",5)->connectTo(m3->gate("in",1));
              m3->gate("out",1)->connectTo(gw1->gate("in",5));

              state=REMOVE_CH5;
              cnt=0;
              isSent=false;
              m3->callInitialize();

          }
          break;
       case REMOVE_CH5:
          if(cnt<3)
          {
              cModule *m3 = getParentModule ()-> getSubmodule("ClusterHead5");
              cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

              if (strcmp("ClusterHead5", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),gw1, "out",0);
              }
              if (strcmp("MainClusterHead", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
              }
              if (strcmp("GateWay1", getName()) == 0)
              {
                  if(cnt<4 || cnt>5 )
                      sendDirect(new cMessage("LeavingMsg"),m3, "out",1);
                  else
                      sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("LeavingMsg"),chM, "out",2);
              }
              cnt++;
          }
          else
          {
              eliminateNode("ClusterHead3");
              createNode("ClusterHead3","p=43,146");
                 cModule *nn7 = getParentModule ()-> getSubmodule("ClusterHead3");
                 cModule *gw1 = getParentModule ()-> getSubmodule("GateWay6");

                 gw1->setGateSize("in",7);
                 gw1->setGateSize("out",7);

                 nn7->gate("out",1)->connectTo(gw1->gate("in",6));
                 gw1->gate("out",6)->connectTo(nn7->gate("in",1));

                 state=REMOVE_CH3;
                 cnt=0;
                 isSent=false;
                 nn7->callInitialize();

          }
          break;
       case REMOVE_CH3:
         if(cnt<2)
         {
             cModule *gw6 = getParentModule ()-> getSubmodule("GateWay6");
             cModule *nn7 = getParentModule ()-> getSubmodule("ClusterHead3");
             if (strcmp("ClusterHead3", getName()) == 0)
             {
                 sendDirect(new cMessage("LeavingMsg"),gw6, "out",0);
             }
             if (strcmp("MainClusterHead", getName()) == 0)
             {
                 if(!isSent)
                     sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
                 else
                     sendDirect(new cMessage("LeavingMsg"),gw6, "out",6);
             }
             if (strcmp("BS", getName()) == 0)
             {
                 sendDirect(new cMessage("LeavingMsg"),chM, "out",0);
             }

             cnt++;
         }
         else
         {
             createNode("ClusterHead5","p=237,420");

              cModule *m3 = getParentModule ()-> getSubmodule("ClusterHead5");
              cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

              gw1->gate("out",3)->connectTo(m3->gate("in",1));
              m3->gate("out",1)->connectTo(gw1->gate("in",3));

              cGate *outg=gw1->gate("out",3);
              outg->setDisplayString("ls=red");
              outg=m3->gate("out",1);
              outg->setDisplayString("ls=red");

              state=REJOIN_CH5;
              cnt=0;
              isSent=false;
              m3->callInitialize();
         }
         break;


       case REJOIN_CH5:
          if(cnt<7)
          {
              cModule *m3 = getParentModule ()-> getSubmodule("ClusterHead5");
              cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

              if (strcmp("ClusterHead5", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),gw1, "out",0);
              }
              if (strcmp("MainClusterHead", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
              }
              if (strcmp("GateWay1", getName()) == 0)
              {
                  if(cnt<4 || cnt>5 )
                      sendDirect(new cMessage("ConnectionMsg"),m3, "out",1);
                  else
                      sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",2);
              }
              cnt++;
          }
          else
          {
              cancelAndDelete(msg);
              cModule *m3 = getParentModule ()-> getSubmodule("ClusterHead5");
              cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

              cGate *outg=m3->gate("out",1);
              outg->setDisplayString("ls=black");
              outg=gw1->gate("out",3);
              outg->setDisplayString("ls=black");

              m3->setDisplayString("i=block/routing");


              eliminateNode("ClusterHead13");
               createNode("ClusterHead13","p=80,416");
                cModule *n13 = getParentModule ()-> getSubmodule("ClusterHead13");

                gw1->setGateSize("in",8);
                gw1->setGateSize("out",8);

                n13->gate("out",1)->connectTo(gw1->gate("in",7));
                gw1->gate("out",7)->connectTo(n13->gate("in",1));

                state=REMOVE_THIRTEEN;
                cnt=0;
                isSent=false;
                n13->callInitialize();



          }
          break;



       case REMOVE_THIRTEEN:
           if(cnt<2)
           {
               cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

               if (strcmp("MainClusterHead", getName()) == 0)
               {
                   if(!isSent)
                   {
                       sendDirect(new cMessage("LeavingMsg"),bs, "out",0);
                       isSent=true;
                   }
                   else
                   {
                       sendDirect(new cMessage("LeavingMsg"),gw1, "out",7);
                       isSent=false;
                   }
               }

               if (strcmp("ClusterHead13", getName()) == 0)
                {
                    sendDirect(new cMessage("LeavingMsg"),gw1, "out",0);
                }
               cnt++;
           }
           else
           {
               eliminateNode("GateWay2");
               createNode("GateWay2","p=352,171");
               cModule *nn4 = getParentModule ()-> getSubmodule("GateWay2");

               chM->setGateSize("in",8);
               chM->setGateSize("out",8);

               nn4->gate("out",0)->connectTo(chM->gate("in",7));
               chM->gate("out",7)->connectTo(nn4->gate("in",0));

               state=REMOVE_GW2;
               cnt=0;
               isSent=false;
               nn4->callInitialize();
           }
           break;
       case REMOVE_GW2:
           if(cnt<1)
           {
               if (strcmp("GateWay2", getName()) == 0)
               {
                   if(!isSent)
                       sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                   isSent=true;
               }
               if (strcmp("BS", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",7);
               }

               cnt++;
           }
           else
           {
               eliminateNode("GateWay6");
                  createNode("GateWay6","p=115,164");
                  cModule *nn4 = getParentModule ()-> getSubmodule("GateWay6");

                  chM->setGateSize("in",9);
                  chM->setGateSize("out",9);

                  nn4->gate("out",0)->connectTo(chM->gate("in",8));
                  chM->gate("out",8)->connectTo(nn4->gate("in",0));

                  state=REMOVE_GW6;
                  cnt=0;
                  isSent=false;
                  nn4->callInitialize();
           }
           break;
       case REMOVE_GW6:
          if(cnt<1)
          {
              if (strcmp("GateWay6", getName()) == 0)
              {
                  if(!isSent)
                      sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                  isSent=true;
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",8);
              }

              cnt++;
          }
          else
          {

              createNode("GateWay2","p=352,171");
              cModule *nn4 = getParentModule ()-> getSubmodule("GateWay2");

              nn4->gate("out",0)->connectTo(chM->gate("in",4));
              chM->gate("out",4)->connectTo(nn4->gate("in",0));

              cGate *outg=nn4->gate("out",0);
              outg->setDisplayString("ls=red");
              outg=chM->gate("out",4);
              outg->setDisplayString("ls=red");

              state=REJOIN_GW2;
              cnt=0;
              isSent=false;
              nn4->callInitialize();
         }
        break;

       case REJOIN_GW2:
           if(cnt<3)
           {
               if (strcmp("GateWay2", getName()) == 0)
               {
                   if(!isSent)
                       sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                   isSent=true;
               }
               if (strcmp("BS", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",4);
               }
               if (strcmp("GateWay1", getName()) == 0)
               {
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
               }
               cnt++;
           }
           else
           {
               cModule *nn4 = getParentModule ()-> getSubmodule("GateWay2");

               cGate *outg=nn4->gate("out",0);
               outg->setDisplayString("ls=black");
               outg=chM->gate("out",4);
               outg->setDisplayString("ls=black");

               nn4->setDisplayString("i=device/switch");

              eliminateNode("ClusterHead5");

             createNode("ClusterHead5","p=237,420");

             cModule *m3 = getParentModule ()-> getSubmodule("ClusterHead5");
             cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

             //gw1->setGateSize("in",6);
             //gw1->setGateSize("out",6);

             gw1->gate("out",5)->connectTo(m3->gate("in",1));
             m3->gate("out",1)->connectTo(gw1->gate("in",5));

             state=REMOVE_REJOIN_CH5;
             cnt=0;
             isSent=false;
             m3->callInitialize();

           }
           break;

       case REMOVE_REJOIN_CH5:
         if(cnt<3)
         {
             cModule *m3 = getParentModule ()-> getSubmodule("ClusterHead5");
             cModule *gw1 = getParentModule ()-> getSubmodule("GateWay1");

             if (strcmp("ClusterHead5", getName()) == 0)
             {
                 sendDirect(new cMessage("LeavingMsg"),gw1, "out",0);
             }
             if (strcmp("MainClusterHead", getName()) == 0)
             {
                 sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
             }
             if (strcmp("GateWay1", getName()) == 0)
             {
                 if(cnt<4 || cnt>5 )
                     sendDirect(new cMessage("LeavingMsg"),m3, "out",1);
                 else
                     sendDirect(new cMessage("LeavingMsg"),chM, "out",1);
             }
             if (strcmp("BS", getName()) == 0)
             {
                 sendDirect(new cMessage("LeavingMsg"),chM, "out",2);
             }
             cnt++;
         }
         else
         {
              eliminateNode("GateWay2");
              createNode("GateWay2","p=352,171");
              cModule *nn4 = getParentModule ()-> getSubmodule("GateWay2");

              nn4->gate("out",0)->connectTo(chM->gate("in",4));
              chM->gate("out",4)->connectTo(nn4->gate("in",0));

              cGate *outg=nn4->gate("out",0);
              outg->setDisplayString("ls=red");
              outg=chM->gate("out",4);
              outg->setDisplayString("ls=red");

              state=REMOVE_REJOIN_GW2;
              cnt=0;
              isSent=false;
              nn4->callInitialize();

         }
         break;


       case REMOVE_REJOIN_GW2:
          if(cnt<1)
          {
              if (strcmp("GateWay2", getName()) == 0)
              {
                  if(!isSent)
                      sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
                  isSent=true;
              }
              if (strcmp("BS", getName()) == 0)
              {
                  sendDirect(new cMessage("ConnectionMsg"),chM, "out",7);
              }

              cnt++;
          }
          else
          {
                 eliminateNode("GateWay1");
                createNode("GateWay1","p=100,281");

                chM->setGateSize("in",12);
                chM->setGateSize("out",12);

                cModule *nn4 = getParentModule ()-> getSubmodule("GateWay1");

                nn4->gate("out",1)->connectTo(chM->gate("in",11));
                chM->gate("out",11)->connectTo(nn4->gate("in",1));

                state=REMOVE_GW1;
                cnt=0;
                isSent=false;
                nn4->callInitialize();
          }
          break;


    case REMOVE_GW1:
       if(cnt<1)
       {
           if (strcmp("GateWay1", getName()) == 0)
           {
               if(!isSent)
                   sendDirect(new cMessage("ConnectionMsg"),chM, "out",1);
               isSent=true;
           }
           if (strcmp("BS", getName()) == 0)
           {
               sendDirect(new cMessage("ConnectionMsg"),chM, "out",9);
           }

           cnt++;
       }
       else
       {
           eliminateNode("GateWay1");
       }
       break;

    }

}

void Node::createNode(char* NodeName,char* NodePosition)
{
    // create
    cModuleType *moduleType = cModuleType::get("dcwsn_11_02.simulations.Node");
    cModule *module = moduleType->create(NodeName, this->getParentModule());

    // set up parameters and gate sizes before we set up its submodules

    module->finalizeParameters();

    module->setGateSize("out",5);
    module->setGateSize("in",5);
          // create internals, and schedule it
    module->buildInside();
    module->scheduleStart(simTime()+exponential(1.0));
    module->setDisplayString(NodePosition);
}

void Node::eliminateNode(char* NodeName)
{
    cModule *elnode = getParentModule ()-> getSubmodule(NodeName);
    elnode->deleteModule();
}

void Node::checkSecurity()
{
    cModule *bs = getParentModule ()-> getSubmodule("BS");
    sendDirect(new cPacket("SecurityPkt"),bs, "out",1);
}

void Node::finish()
{
    // This function is called by OMNeT++ at the end of the simulation.
    EV << "Sent:     " << numSent << endl;
    EV << "Received: " << numReceived << endl;
    EV << "Hop count, min:    " << hopCountStats.getMin() << endl;
    EV << "Hop count, max:    " << hopCountStats.getMax() << endl;
    EV << "Hop count, mean:   " << hopCountStats.getMean() << endl;
    EV << "Hop count, stddev: " << hopCountStats.getStddev() << endl;

    recordScalar("#sent", numSent);
    recordScalar("#received", numReceived);

    hopCountStats.recordAs("hop count");
}


char *substring(size_t start, size_t stop, const char *src, char *dst, size_t size)
{
   int count = stop - start;
   if ( count >= --size )
   {
      count = size;
   }
   sprintf(dst, "%.*s", count, src + start);
   return dst;
}
char *substr(char *string, int begin, int end){
    char* temp = new char[end-begin+1];
    strncpy(temp, string+begin, end-begin+1);
    temp[end-begin+1] = '\0';
    return temp;
}
int getPosX(const char* strPos)
{
    char* px;
    px=substr((char*)strPos,2,5);//,strPos,px,3);
    return (int)px;
}
int getPosY(const char* strPos)
{
    char* py;
    py=substr((char*)strPos,6,9);//,strPos,py,3);
    return (int)py;
}
double Node::calDistance(char* SourceNode,char* TargetNode)
{
    cModule *sn = getParentModule ()-> getSubmodule(SourceNode);
    const char* SPos=sn->getDisplayString();
    int spx=getPosX(SPos);
    int spy=getPosY(SPos);

    cModule *tn = getParentModule ()-> getSubmodule(TargetNode);
    const char* TPos=tn->getDisplayString();
    int tpx=getPosX(TPos);
    int tpy=getPosY(TPos);

    return sqrt((tpx - spx)*(tpx - spx) + (tpy - spy)*(tpy - spy));
}


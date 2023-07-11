//
// Copyright (C) 2018 Christoph Sommer <sommer@ccs-labs.org>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "veins_inet/VeinsInetSampleApplication.h"

#include "inet/common/ModuleAccess.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include <iostream>
#include <string>


#include "veins_inet/VeinsInetSampleMessage_m.h"

using namespace std;

using namespace inet;

Define_Module(VeinsInetSampleApplication);

VeinsInetSampleApplication::VeinsInetSampleApplication()
{
}

const char* msgr[9];

int msgRec=0;
int lastC=42;

const char* pastVal0="";
const char* pastVal1="";
const char* pastVal2="";
const char* pastVal3="";
const char* pastVal4="";
const char* pastVal5="";
const char* pastVal6="";
const char* pastVal7="";
const char* pastVal8="";
const char* pastVal9="";
const char* pastVal01="";
const char* pastVal11="";
const char* pastVal21="";
const char* pastVal31="";
const char* pastVal41="";
const char* pastVal51="";
const char* pastVal61="";
const char* pastVal71="";
const char* pastVal81="";
const char* pastVal02="";
const char* pastVal12="";
const char* pastVal22="";
const char* pastVal32="";
const char* pastVal42="";
const char* pastVal52="";
const char* pastVal62="";
const char* pastVal72="";
const char* pastVal82="";
const char* pastVal03="";
const char* pastVal13="";
const char* pastVal23="";
const char* pastVal33="";
const char* pastVal43="";
const char* pastVal53="";
const char* pastVal63="";
const char* pastVal73="";
const char* pastVal83="";

bool VeinsInetSampleApplication::startApplication()
{
    // host[0] should stop at t=20s
/*
    //Sim1
    if (getParentModule()->getIndex() == 0) {
        auto callback = [this]() {
            getParentModule()->getDisplayString().setTagArg("i", 1, "red");

            traciVehicle->setSpeed(0);

            auto payload = makeShared<VeinsInetSampleMessage>();
            payload->setChunkLength(B(100));
            payload->setRoadId(traciVehicle->getRoadId().c_str());
            timestampPayload(payload);

            auto packet = createPacket("Accident");
            packet->insertAtBack(payload);
            sendPacket(std::move(packet));

            // host should continue after 30s
            auto callback = [this]() {
                traciVehicle->setSpeed(-1);
            };
            timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(74000, SIMTIME_MS)));
        };
        int cont=70150;
        timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(70150, SIMTIME_MS)));//while, el callback espera a la senal
    }
*/

    //sim2
    //roadID refers to the srcID
    //wait till all nodes appear 12 segs
    //los nodos tienen tablas de mensajes
    /*
    srand((unsigned) time(NULL));
    double cont=0;
    int cont2=0;
    int updateTimet=2000;
    int startTimet=14000;
    if (getParentModule()->getIndex() != 1 and getParentModule()->getIndex() != 6 and getParentModule()->getIndex() != 9) {
            auto callback = [this]() {
                getParentModule()->getDisplayString().setTagArg("i", 1, "red");
                //Los vehiculos deben estar en la simulacion
                //otro caso un vehiculo cambia de carril, el otro desacelera
                //traciVehicle->setSpeed(0);

                auto payload = makeShared<VeinsInetSampleMessage>();
                payload->setChunkLength(B(100));
                //payload->setChunkLength(B(rand()%100));
                //payload->setRoadId(traciVehicle->getRoadId().c_str());
                int a=getParentModule()->getIndex();
                payload->setRoadId(("E"+ std::to_string(a)).c_str());

                //payload->setRoadId((getParentModule()->getIndex().c_str()+cont2.c_str()).c_str());
                timestampPayload(payload);

                auto packet = createPacket("detectionsUpdate");
                packet->insertAtBack(payload);
                sendPacket(std::move(packet));

                //haveForwarded = true;


                // host should continue after 30s
                //auto callback = [this]() {
                //    traciVehicle->setSpeed(-1);
                //};


                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(14500+rand()%100, SIMTIME_MS)));

                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(16500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(18500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(20500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(22500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(24500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(26500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(28500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(30500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(32500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(34500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(36500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(38500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(40500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(42500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(44500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(46500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(48500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(50500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(52500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(54500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(56500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(58500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(60500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(62500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(64500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(66500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(68500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(70500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(72500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(74500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(cont+1000, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(cont+1000, SIMTIME_MS)));


            };
            //int random = rand() % 100;
            //cont=startTimett+random*10;
            //simtime_t a=24000;
            //cont=24000;
            //Probar frec, elegir un tiempo maximo simulacion 120
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(14000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(16000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(18000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(20000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(22000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(24000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(26000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(28000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(30000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(32000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(34000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(36000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(38000+rand()%100, SIMTIME_MS)));
            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(40000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(40000+rand()%100, SIMTIME_MS)));

            }
            //reset Mensajes viejos

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(41000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(41000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(42000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(42000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(43000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(43000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(44000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(44000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(45000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(45000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(46000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(46000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(47000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(47000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(48000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(48000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(49000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(49000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(50000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(50000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(51000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(51000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(52000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(52000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(53000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(53000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(54000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(54000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(55000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(55000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(56000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(56000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(57000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(57000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(58000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(58000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(59000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(59000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(60000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(60000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(61000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(61000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(62000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(62000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(63000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(63000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(64000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(64000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(65000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(65000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(66000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(66000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(67000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(67000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(68000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(68000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(69000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(69000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(70000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(70000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(71000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(71000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(72000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(72000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(73000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(73000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(74000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(74000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(75000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(75000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(76000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(76000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(77000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(77000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(78000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(78000+rand()%100, SIMTIME_MS)));

            }

            if (getParentModule()->getIndex() == 2) {

                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(79000, SIMTIME_MS)));

                        }
                        else{
                            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(79000+rand()%100, SIMTIME_MS)));

                        }

            if (getParentModule()->getIndex() == 2) {

                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(80000, SIMTIME_MS)));

            }
            else{
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(80000+rand()%100, SIMTIME_MS)));

            }
            //random = rand();
            //cont=startTimet+updateTimet+random*100;
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(cont, SIMTIME_MS)));
            //random = rand();
            //cont=startTimet+updateTimet*2+random*100;
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(cont, SIMTIME_MS)));

    }
    */
/*

    //sim3
    //cambio de via, los coches desaceleran
    //un coche se incorpora

    if (getParentModule()->getIndex() == 6) {
            auto callback = [this]() {
                getParentModule()->getDisplayString().setTagArg("i", 1, "red");

                //traciVehicle->changeRoute("E31", 200000);
                traciVehicle->setSpeed(2);

                auto payload = makeShared<VeinsInetSampleMessage>();
                payload->setChunkLength(B(100));
                payload->setRoadId(traciVehicle->getRoadId().c_str());
                timestampPayload(payload);

                auto packet = createPacket("ChangingLane");
                packet->insertAtBack(payload);
                sendPacket(std::move(packet));

                // host should continue after 30s
                auto callback = [this]() {
                    traciVehicle->setSpeed(-1);
                };
                timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(185000, SIMTIME_MS)));
            };
            timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(165000, SIMTIME_MS)));//while, el callback espera a la senal
        }
*/

    //SIM4
    srand((unsigned) time(NULL));
    double cont=0;
    int cont2=0;
    int updateTimet=200;
    //int startTimet=14000;
    if (getParentModule()->getIndex() != 1 and getParentModule()->getIndex() != 6 and getParentModule()->getIndex() != 9) {
            auto callback = [this]() {
                getParentModule()->getDisplayString().setTagArg("i", 1, "red");
                //Los vehiculos deben estar en la simulacion
                //otro caso un vehiculo cambia de carril, el otro desacelera
                //traciVehicle->setSpeed(0);

                auto payload = makeShared<VeinsInetSampleMessage>();
                payload->setChunkLength(B(100));
                //payload->setChunkLength(B(rand()%100));
                //payload->setRoadId(traciVehicle->getRoadId().c_str());
                int a=getParentModule()->getIndex();
                payload->setRoadId(("E"+ std::to_string(a)).c_str());

                //payload->setRoadId((getParentModule()->getIndex().c_str()+cont2.c_str()).c_str());
                timestampPayload(payload);

                auto packet = createPacket("detectionsUpdate");
                packet->insertAtBack(payload);
                sendPacket(std::move(packet));

                //haveForwarded = true;


                // host should continue after 30s
                //auto callback = [this]() {
                //    traciVehicle->setSpeed(-1);
                //};


                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(14500+rand()%100, SIMTIME_MS)));

                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(16500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(18500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(20500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(22500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(24500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(26500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(28500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(30500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(32500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(34500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(36500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(38500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(40500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(42500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(44500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(46500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(48500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(50500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(52500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(54500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(56500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(58500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(60500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(62500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(64500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(66500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(68500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(70500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(72500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(74500+rand()%100, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(cont+1000, SIMTIME_MS)));
                //timerManager.create(veins::TimerSpecification(callback).oneshotIn(SimTime(cont+1000, SIMTIME_MS)));


            };
            //int random = rand() % 100;
            //cont=startTimett+random*10;
            //simtime_t a=24000;
            //cont=24000;
            //Probar frec, elegir un tiempo maximo simulacion 120
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(14000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(16000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(18000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(20000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(22000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(24000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(26000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(28000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(30000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(32000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(34000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(36000+rand()%100, SIMTIME_MS)));
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(38000+rand()%100, SIMTIME_MS)));
            while((21000+cont*updateTimet)<=40000){
                timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(21000+cont*updateTimet+rand()%100, SIMTIME_MS)));
                cont=cont+1;
            }
//sim 1 40000-80000
            //sim2 21000 - 40000
//SIM3 32000-56000
            //random = rand();
            //cont=startTimet+updateTimet+random*100;
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(cont, SIMTIME_MS)));
            //random = rand();
            //cont=startTimet+updateTimet*2+random*100;
            //timerManager.create(veins::TimerSpecification(callback).oneshotAt(SimTime(cont, SIMTIME_MS)));

    }

    return true;
}

bool VeinsInetSampleApplication::stopApplication()
{
    return true;
}

VeinsInetSampleApplication::~VeinsInetSampleApplication()
{
}

void VeinsInetSampleApplication::processPacket(std::shared_ptr<inet::Packet> pk)
{
/*
    //sim1
    auto payload = pk->peekAtFront<VeinsInetSampleMessage>();

    EV_INFO << "Received packet: " << payload << endl;
    //EV_DETAIL << "Content: " << payload->getRoadId().c_str() << endl;

    getParentModule()->getDisplayString().setTagArg("i", 1, "green");

    //traciVehicle->changeRoute(payload->getRoadId(), 999.9);
    const char* aux = "E18";
        const char* aux2 = "E14";
        const char* aux3 = "E16";

        //if(getParentModule()->getIndex()==4){
        //Los vehiculos en la seccion de la ruta 29 desaceleran
        if(strcmp(traciVehicle->getRoadId().c_str(), aux)==0 or strcmp(traciVehicle->getRoadId().c_str(), aux2)==0 or strcmp(traciVehicle->getRoadId().c_str(), aux3)==0){
            traciVehicle->setSpeed(1);
        }

    if (haveForwarded) return;

    auto packet = createPacket("relay");
    packet->insertAtBack(payload);
    sendPacket(std::move(packet));

    haveForwarded = true;
    //getParentModule()->getDisplayString().setTagArg("i", 1, "gray");
*/


    //sim2
    const char* aux=""; //buffer
    const char* aux2="";
    const char* aux3="";
    const char* aux4="";

    //getParentModule()->getDisplayString().setTagArg("i", 1, "gray");

    auto payload = pk->peekAtFront<VeinsInetSampleMessage>();
    double t2 = simTime().dbl();
    if(lastC+0.0<t2){
        lastC=lastC+0.2;//1 0.5 0.2

        pastVal0="";
        pastVal1="";
        pastVal2="";
        pastVal3="";
        pastVal4="";
        pastVal5="";
        pastVal6="";
        pastVal7="";
        pastVal8="";
        pastVal9="";
        pastVal01="";
        pastVal11="";
        pastVal21="";
        pastVal31="";
        pastVal41="";
        pastVal51="";
        pastVal61="";
        pastVal71="";
        pastVal81="";
        pastVal02="";
        pastVal12="";
        pastVal22="";
        pastVal32="";
        pastVal42="";
        pastVal52="";
        pastVal62="";
        pastVal72="";
        pastVal82="";
        pastVal03="";
               pastVal13="";
               pastVal23="";
               pastVal33="";
               pastVal43="";
               pastVal53="";
               pastVal63="";
               pastVal73="";
               pastVal83="";

    }

    if(getParentModule()->getIndex()==0){
        aux=pastVal0;
        aux2=pastVal01;
        aux3=pastVal02;
        aux4=pastVal03;
    }
    if(getParentModule()->getIndex()==1){
           aux=pastVal1;
           aux2=pastVal11;
           aux3=pastVal12;
           aux4=pastVal13;
       }
    if(getParentModule()->getIndex()==2){
           aux=pastVal2;
           aux2=pastVal21;
           aux3=pastVal22;
           aux4=pastVal23;
       }
    if(getParentModule()->getIndex()==3){
           aux=pastVal3;
           aux2=pastVal31;
           aux3=pastVal32;
           aux4=pastVal33;
       }
    if(getParentModule()->getIndex()==4){
           aux=pastVal4;
           aux2=pastVal41;
           aux3=pastVal42;
           aux4=pastVal43;
       }
    if(getParentModule()->getIndex()==5){
           aux=pastVal5;
           aux2=pastVal51;
           aux3=pastVal52;
           aux4=pastVal53;
       }
    if(getParentModule()->getIndex()==6){
           aux=pastVal6;
           aux2=pastVal61;
           aux3=pastVal62;
           aux4=pastVal63;
       }
    if(getParentModule()->getIndex()==7){
           aux=pastVal7;
           aux2=pastVal71;
           aux3=pastVal72;
           aux4=pastVal73;
       }
    if(getParentModule()->getIndex()==8){
           aux=pastVal8;
           aux2=pastVal81;
           aux3=pastVal82;
           aux4=pastVal83;
       }

    simtime_t a=simTime();
    EV_INFO << "Received packet1: " << payload<< " ruta "<<payload->getRoadId() << " vs "<< aux <<" vs " <<aux2<<" vs "<<aux3<<" tiempo "<<a<<" lastC "<<lastC<<endl;
    //EV_INFO << "Received packet2: " << payload<< " ruta "<<payload->getLength() << " vs "<< aux <<endl;
    //EV_DETAIL << "Content: " << payload->getRoadId().c_str() << endl;

    getParentModule()->getDisplayString().setTagArg("i", 1, "green");


    if (strcmp(payload->getRoadId(), aux) == 0){
    //if (strcmp(payload->getChunkLength(), aux) == 0){
        haveForwarded = true;
    }
    else{
        if (strcmp(payload->getRoadId(), aux2) == 0){
            //if (strcmp(payload->getChunkLength(), aux) == 0){
                haveForwarded = true;
        }
        else{
            if (strcmp(payload->getRoadId(), aux3) == 0){
                //if (strcmp(payload->getChunkLength(), aux) == 0){
                    haveForwarded = true;
                }
            else{
                if (strcmp(payload->getRoadId(), aux4) == 0){
                                //if (strcmp(payload->getChunkLength(), aux) == 0){
                                    haveForwarded = true;
                                }
                            else{
                                haveForwarded = false;
                            }

            }
        }
    }

    //traciVehicle->changeRoute(payload->getRoadId(), 999.9);

    if (haveForwarded){
        //return;
    }
    else{
        auto packet = createPacket("relay");
        packet->insertAtBack(payload);
        sendPacket(std::move(packet));

        //haveForwarded = true;
        //msgr[getParentModule()->getIndex()]=payload->getRoadId();
        if(getParentModule()->getIndex()==0){
            if(!haveForwarded){
                pastVal03=pastVal02;
                pastVal02=pastVal01;
                pastVal01=pastVal0;
                pastVal0=payload->getRoadId();
            }
        }
        if(getParentModule()->getIndex()==1){
            if(!haveForwarded){
                            pastVal13=pastVal12;
                            pastVal12=pastVal11;
                            pastVal11=pastVal1;
                            pastVal1=payload->getRoadId();
                        }
        }
        if(getParentModule()->getIndex()==2){
            if(!haveForwarded){
                pastVal23=pastVal22;

                            pastVal22=pastVal21;
                            pastVal21=pastVal2;
                            pastVal2=payload->getRoadId();
                        }
           }
        if(getParentModule()->getIndex()==3){
            if(!haveForwarded){
                pastVal33=pastVal32;

                            pastVal32=pastVal31;
                            pastVal31=pastVal3;
                            pastVal3=payload->getRoadId();
                        }
           }
        if(getParentModule()->getIndex()==4){
            if(!haveForwarded){
                pastVal43=pastVal42;

                            pastVal42=pastVal41;
                            pastVal41=pastVal4;
                            pastVal4=payload->getRoadId();
                        }
           }
        if(getParentModule()->getIndex()==5){
            if(!haveForwarded){
                pastVal53=pastVal52;

                pastVal52=pastVal51;
                            pastVal51=pastVal5;
                            pastVal5=payload->getRoadId();
                        }
           }
        if(getParentModule()->getIndex()==6){
            if(!haveForwarded){
                pastVal63=pastVal62;

                            pastVal62=pastVal61;
                            pastVal61=pastVal6;
                            pastVal6=payload->getRoadId();
                        }
           }
        if(getParentModule()->getIndex()==7){
            if(!haveForwarded){
                pastVal73=pastVal72;

                pastVal72=pastVal71;
                            pastVal71=pastVal7;
                            pastVal7=payload->getRoadId();
                        }
           }
        if(getParentModule()->getIndex()==8){
            if(!haveForwarded){
                pastVal83=pastVal82;

                pastVal82=pastVal81;
                            pastVal81=pastVal8;
                            pastVal8=payload->getRoadId();
                        }
           }
    }
/*

//sim3
    //Se hace equivalencia de las rutas con el carril
        auto payload = pk->peekAtFront<VeinsInetSampleMessage>();

        EV_INFO << "Received packet2: " << payload << " ruta actual " << traciVehicle->getRoadId()<<endl;
        //EV_DETAIL << "Content: " << payload->getRoadId().c_str() << endl;

        getParentModule()->getDisplayString().setTagArg("i", 1, "green");
        const char* aux = "E29";
        //if(getParentModule()->getIndex()==4){
        //Los vehiculos en la seccion de la ruta 29 desaceleran
        if(strcmp(traciVehicle->getRoadId().c_str(), aux)==0){
            traciVehicle->setSpeed(2);
        }

        if (haveForwarded) return;

        auto packet = createPacket("relay");
        packet->insertAtBack(payload);
        sendPacket(std::move(packet));

        haveForwarded = true;
        //getParentModule()->getDisplayString().setTagArg("i", 1, "gray");
*/
}

//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package dcwsn_11_02.simulations;

simple Node
{
    parameters:
        bool sendMsgOnInit = default(true); // whether the module should send out a message on initialization
        int limit = default(2);   // another parameter with a default value
        @display("i=block/wrx");
    gates:
        input in[];
        output out[];
}


network SimulationNetwork
{
    @display("bgb=717,553");
    submodules:
        newNode: Node {
            @display("p=115,164");
        }
        MainClusterHead: Node {
            @display("p=254,192;i=block/routing");
        }
        BS: Node {
            @display("p=328,102;i=device/router");
        }
    connections:
        newNode.out++ --> { @display("ls=red"); } --> MainClusterHead.in++;
        MainClusterHead.out++ --> { @display("ls=red"); } --> newNode.in++;
        MainClusterHead.out++ --> BS.in++;
        BS.out++ --> MainClusterHead.in++;
}
@statistic[SimulationNetwork](record=count,mean,max?,vector?);
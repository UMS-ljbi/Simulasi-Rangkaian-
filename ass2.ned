// Lim Jun Yan (BI20110128), Siow Wei Jun (BI20110084), Liew San Loong (BI20110105)

simple pclaptop
{
    parameters:
        @display("i=device/laptop");
        @display("i=,black");
    gates:
        input radioIn @directIn;
}

simple w_router
{
    parameters:
        @display("i=device/router");
        @display("i=,yellow");
    gates:
        input radioIn @directIn;
}

network WirelessNetwork
{
    @display("bgb=418,284");
    submodules:
        Laptop1: pclaptop {
            @display("p=130,71");            
        }

        Laptop2: pclaptop {
            @display("p=281,71");
        }
        Router: w_router {
            @display("p=199,169");
        }
}


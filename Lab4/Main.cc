/*Main.cc
*/

#include "NodeTB.hh"
#include "BSTB.hh"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std; 

int main(){
    BSTB* test = new BSTB(); 
    test->insert("babe");
    test->printTreeio(); 
    test->insert("rest"); 
    test->printTreeio(); 
    test->insert("wanton");
    test->printTreeio(); 
    test->insert("shawn");
    test->printTreeio(); 
    test->insert("dunce");
    test->printTreeio(); 
    test->insert("fabric");
    test->printTreeio(); 
    test->insert("deject");
    test->printTreeio(); 
    test->insert("chars");
    test->insert("master");
    test->insert("lose");
    test->insert("believe");
    test->insert("grange");
    test->insert("juice");
    test->insert("super");
    test->insert("sort");
    test->insert("hand"); 
    test->insert("frisbee");
    test->insert("running");
    test->insert("older");
    test->insert("tint");
    test->insert("appease");
    test->insert("might");
    return 0; 
}

#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "RemovePrimerPlugin.h"

void RemovePrimerPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void RemovePrimerPlugin::run() {}

void RemovePrimerPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "sed";
myCommand += " 's/^";
myCommand += parameters["primer"];
myCommand += "//' ";
myCommand += parameters["fastafile"];
myCommand += " > "+file;
 system(myCommand.c_str());
}

PluginProxy<RemovePrimerPlugin> RemovePrimerPluginProxy = PluginProxy<RemovePrimerPlugin>("RemovePrimer", PluginManager::getInstance());

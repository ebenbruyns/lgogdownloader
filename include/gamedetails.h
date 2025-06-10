/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details. */

#ifndef GAMEDETAILS_H
#define GAMEDETAILS_H

#include "globalconstants.h"
#include "globals.h"
#include "gamefile.h"
#include "config.h"
#include "util.h"

#include <iostream>
#include <vector>
#include <json/json.h>

class gameDetails
{
    public:
        gameDetails();
        std::vector<gameFile> extras;
        std::vector<gameFile> installers;
        std::vector<gameFile> patches;
        std::vector<gameFile> languagepacks;
        std::vector<gameDetails> dlcs;
        std::string gamename;
        std::string gamename_basegame;
        std::string product_id;
        std::string title;
        std::string title_basegame;
        std::string icon;
        std::string serials;
        std::string changelog;
        std::string logo;
        std::string gameDetailsJson;
        std::string productJson;
        void filterWithPriorities(const gameSpecificConfig& config);
        void makeFilepaths(const DirectoryConfig& config);
        std::string getSerialsFilepath();
        std::string getLogoFilepath();
        std::string getIconFilepath();
        std::string getChangelogFilepath();
        std::string getGameDetailsJsonFilepath();
        std::string getProductJsonFilepath();
        Json::Value getDetailsAsJson();
        std::vector<gameFile> getGameFileVector();
        std::vector<gameFile> getGameFileVectorFiltered(const unsigned int& iType);
        void filterWithType(const unsigned int& iType);
        std::string makeCustomFilepath(const std::string& filename, const gameDetails& gd, const DirectoryConfig& dirConf);
        virtual ~gameDetails();
    protected:
        void filterListWithPriorities(std::vector<gameFile>& list, const gameSpecificConfig& config);
        void filterListWithType(std::vector<gameFile>& list, const unsigned int& iType);
        std::string makeFilepath(const gameFile& gf, const DirectoryConfig& dirConf);
    private:
        std::string serialsFilepath;
        std::string logoFilepath;
        std::string iconFilepath;
        std::string changelogFilepath;
        std::string gameDetailsJsonFilepath;
        std::string productJsonFilepath;
};

#endif // GAMEDETAILS_H

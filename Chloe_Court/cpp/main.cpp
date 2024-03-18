#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include "class/Manager.h"
#include "class/Photo.h"
#include "class/Video.h"
#include "class/Film.h"
#include "class/Group.h"
#include "tcpserver/tcpserver.h"
#include <regex>
#include <memory>

const int PORT = 3331;

using VideoPtr = std::shared_ptr<Video>;
using PhotoPtr = std::shared_ptr<Photo>;
using FilmPtr = std::shared_ptr<Film>;
using GroupPtr = std::shared_ptr<Group>;
using namespace std;

/**
    * Main function
    * Lance le serveur, crée les objets multimédias les affiche et les joue
*/
int main(int argc, const char* argv[]) {
    Manager manager = Manager();
    
    int chap[3] = {1, 2, 2};

    PhotoPtr photo = manager.createPhoto("Photo1", "../photo/photo1.jpeg", 736, 1104);
    VideoPtr video = manager.createVideo("Video1", "../video/video1.mp4", 5);
    FilmPtr film = manager.createFilm("Film1", "../video/video1.mp4", 5, chap, 3);

    // Create the TCPServer
    auto* server = new TCPServer([&](std::string const& request, std::string& response) {
        
        // Parse the request
        std::stringstream ss(request);
        std::string command;
        ss >> command;
        std::string displayOutput;
        stringstream stream = stringstream();
        std::string responseText;

        // Handle different commands
        if (command == "display") {
            std::stringstream displayOutput;
            
            for (const auto& item : manager.getAllItems()) {
                std::stringstream objOutput;
                manager.searchAndDisplay(item, objOutput);
                displayOutput << "Object: " << item << ", " << objOutput.str() << "    //    ";
            }

            std::string responseText = displayOutput.str(); // Extraire le contenu du stringstream

            // Supprimer les sauts de ligne de la réponse
            std::regex newlines_re("\n+");
            responseText = std::regex_replace(responseText, newlines_re, ", ");

            response = responseText; // Assigner la réponse modifiée
        }
        else if (command == "play") {
            manager.play("Photo1");
            manager.play("Video1");
            manager.play("Film1");
            
            std::string object;
            ss >> object;

        response = "PLAYING: " + object;
        } else {
        // Invalid command
        response = "INVALID_COMMAND";
        }

        // Return true to keep the connection with the client open
        return true;
        });

        // lance la boucle infinie du serveur
        std::cout << "Starting Server on port " << PORT << std::endl;

        int status = server->run(PORT);

        // en cas d'erreur
        if (status < 0)
        {
            std::cerr << "Could not start Server on port " << PORT << std::endl;
            return 1;
        }

    return 0;
}


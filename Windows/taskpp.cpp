#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <windows.h>

std::string DEFAULT_DIRECTORY = "D:/Taskpp/";
std::string DATAFILE_NAME = DEFAULT_DIRECTORY + "dataFile.txt";
std::string VERSION = "1.1.0";
std::string DEFAULT_TEXT_EDITOR = "notepad.exe";

void showHelp() {
    std::cout << "Available commands and usage:\n\n"
              << "- taskpp add \"name\" [\"description\"]: Creates a new task.\n"
              << "- taskpp run \"name\": Executes the task with the given name.\n"
              << "- taskpp remove \"name\": Removes the task with the given name.\n"
              << "- taskpp edit \"name\": Opens the given task file for editing.\n"
              << "- taskpp list: Lists all available tasks.\n"
              << "- taskpp help: Shows available commands and usage.\n"
              << "- taskpp version: Shows the version of Taskpp.\n"
              << "- taskpp info: Shows information about Taskpp.\n\n";
}

void showInfo() {
    std::cout << "Taskpp is simple and open source program for automatizing multiple cli tasks\n"
              << "Programming language used: C++\n"
              << "(github.com/ibmanu) - 2023\n\n";
}

void showVersion() {
    std::cout << "Current Taskpp version: " << VERSION << " for Windows Systems\n\n";
}

void loadData() {
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::string exePath(buffer);
    std::string exeDir = exePath.substr(0, exePath.find_last_of("\\/")) + "\\";

    DEFAULT_DIRECTORY = exeDir;
    DATAFILE_NAME = DEFAULT_DIRECTORY + "dataFile.txt";
}

void addTask(const std::string& name, char* argv[]) {
    std::string filename = DEFAULT_DIRECTORY + name + ".bat";
    std::string command = DEFAULT_TEXT_EDITOR + " " + filename;

    std::ifstream file(filename.c_str());
    std::ofstream dataFile;

    if(file.good()) {
        std::cout << "A task with the same name already exists, if you want to edit it type taskpp edit " + name << "\n\n";
        file.close();
        return;
    }

    int result = std::system(command.c_str());

    if (result != 0) {
        std::cerr << "Error opening the text editor.\n\n";
        file.close();
        return;
    }

    dataFile.open(DATAFILE_NAME, std::ios_base::app);
    if(!dataFile) {
        std::cerr << "Error registering the task." << std::endl;
        dataFile.close();
        return;
    }

    dataFile << "Name: " << name << "  Description:";
    for(int i = 3; argv[i] != nullptr; i++) {
        dataFile << " " << argv[i];
    }
    dataFile << std::endl;
    dataFile.close();

    file.close();

    std::cout << "Task '" << name << "' added successfully.\n\n";
}

void runTask(const std::string& name) {
    std::string filePath = DEFAULT_DIRECTORY + name + ".bat";

    if (std::ifstream(filePath)) {
        int result = system(filePath.c_str());
        if (result == 0) {
            std::cout << "Task '" << name << "' executed successfully.\n\n";
        } else {
            std::cerr << "Failed to execute task '" << name << "'.\n\n";
        }
    } else {
        std::cerr << "Task '" << name << "' not found.\n\n";
    }
}

void removeTask(const std::string& name) {
    std::string fileName = DEFAULT_DIRECTORY + name + ".bat";
    std::ifstream file(fileName.c_str());

    if (!file.good()) {
        std::cout << "Task '" << name << "' not found.\n\n";
        file.close();
        return;
    }

    file.close();
    int result = remove(fileName.c_str());
    if (result != 0) {
        std::cout << "The task '" << name << "' could not be removed\n\n";
        return;
    }

    std::ifstream descriptionsFileIn(DATAFILE_NAME.c_str());
    std::vector<std::string> descriptionLines;

    std::string line;
    while (std::getline(descriptionsFileIn, line)) {
        if (line.find("Name: " + name) != 0) {
            descriptionLines.push_back(line);
        }
    }

    descriptionsFileIn.close();

    std::ofstream descriptionsFileOut(DATAFILE_NAME.c_str());

    for (const std::string& updatedLine : descriptionLines) {
        descriptionsFileOut << updatedLine << '\n';
    }

    descriptionsFileOut.close();

    std::cout << "Task '" << name << "' removed succesfully.\n\n";
}

void editTask(const std::string& name) {
    std::string filename = DEFAULT_DIRECTORY + name + ".bat";
    std::string command = DEFAULT_TEXT_EDITOR + " " + filename;

    std::ifstream file(filename.c_str());

    if(!file.good()) {
        std::cout << "A task with that name doesn't exists, if you want to add a task type taskpp add " + name << "\n\n";
        file.close();
        return;
    }

    int result = std::system(command.c_str());

    if (result != 0) {
        std::cerr << "Error opening the text editor.\n\n";
        file.close();
        return;
    }

    file.close();
    std::cout << "Task '" << name << "' edited successfully.\n\n";
}

void listTasks() {
    std::ifstream dataFileRead(DATAFILE_NAME);
    std::string line;
    
    std::cout << "Current available tasks: \n\n";
    while (std::getline(dataFileRead, line)) {
        std::istringstream iss(line);
        std::string token;

        if (iss >> token && token == "Name:") {
            std::string name;
            iss >> name;

            if (iss >> token && token == "Description:") {
                std::string description;
                while (iss >> token) {
                    description += token + " ";
                }

                std::cout << "Name: " << name << " Description: " << description << std::endl;
            }
        }
    }
    
    dataFileRead.close();
}

int main(int argc, char* argv[]) {

    loadData();

    if (argc < 2) {
        std::cerr << "Usage: taskpp <command> [arguments]" << std::endl;
        std::cout << "If you need help, type taskpp help\n\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "help") {
        showHelp();
    } else if (command == "version") {
        showVersion();
    } else if (command == "info") {
        showInfo();
    } else if (command == "add") {
        addTask(argv[2], argv);
    } else if (command == "run") {
        runTask(argv[2]);
    } else if (command == "remove") {
        removeTask(argv[2]);
    } else if (command == "edit") {
        editTask(argv[2]);
    } else if (command == "list") {
        listTasks();
    } else {
        std::cerr << "Command '" << command << "' not recognized" << std::endl;
        std::cout << "If you need help, type \"taskpp help\"\n\n";
        return 1;
    }

    return 0;
}

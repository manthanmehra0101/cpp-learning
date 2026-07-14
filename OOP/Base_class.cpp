#include <iostream>
class log{
    public:
    const int loglevel = 0;
    const int logLevelwarning = 1;
    const int logLevelerror = 2;  
    const int logLevelinfo = 3;

private:
    int m_logLevel;
public:
    void setLevel(int level){
        std::cout<<"Enter the level: ";
        std::cin>>level;
        m_logLevel = level;
    }
    void Error(const char* message){
        if(m_logLevel >=logLevelerror){
            std::cout<<"[Error]: "<<message<<std::endl;
        }
    }
    void Warn(const char* message){
        if(m_logLevel >= logLevelwarning){
            std::cout<<"[WARNING]: "<<message<<std::endl;
        }
    }
    void Info(const char* message){
        if(m_logLevel >= logLevelinfo){
            std::cout<<"[INFO]: "<<message<<std::endl;
        }
    }
};

int main(){
    log l;
    l.setLevel(3);
    l.Error("This is an error message.");
    l.Warn("This is a warning message.");
    l.Info("This is an info message.");
    return 0;
}
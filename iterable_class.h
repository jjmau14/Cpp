#include <vector>
#include <cstring>

class itor_able {
    
    std::vector<std::string> sentence;
    
public:
    
    itor_able(){}
    void add_item(std::string);
    
    class itor {
        std::vector<std::string> sentence;
        int current_location;
    public:
        itor(std::vector<std::string> &sentence_, int current_location_ = 0) : sentence(sentence_), current_location(current_location_){}
        itor &operator=(const itor_able::itor &);
        itor &operator++();
        itor operator++(int);
        itor &operator--();
        itor operator--(int);
        std::string operator*();
        bool operator==(itor &);
        bool operator!=(itor &);
        
    };
    
    itor begin();
    itor end();
    std::string front();
    std::string back();
    
};
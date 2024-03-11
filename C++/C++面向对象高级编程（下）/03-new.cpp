#include <iostream>
#include <vector> 
#include <string>
 
using namespace std;

typedef enum
{
    ZRCParticipantUserType_Normal = 0,
    ZRCParticipantUserType_SmartTagUser = 1,
} ZRCParticipantUserType;

struct IZRCParticipant
{
    IZRCParticipant(ZRCParticipantUserType t = ZRCParticipantUserType_Normal): type(t) {}
    virtual ~IZRCParticipant() { };
    
    ZRCParticipantUserType type;
};

struct ZRCSmartTagUser: IZRCParticipant
{
    ZRCSmartTagUser(): IZRCParticipant(ZRCParticipantUserType_SmartTagUser) { }
    std::string name;
};

struct ZRCParticipant: IZRCParticipant
{
    ZRCParticipant() : IZRCParticipant(ZRCParticipantUserType_Normal) {} 

    std::string username;

    std::vector<ZRCSmartTagUser> tagUsers;
};


int main(int argc, char **argv)
{
    ZRCParticipant *p = new ZRCParticipant();
    p->username = "P Name";
    ZRCSmartTagUser user1;
    user1.name = "User1";

    ZRCSmartTagUser user2;
    user2.name = "User2";

    p->tagUsers.push_back(user1);
    p->tagUsers.push_back(user2);


    std::vector<IZRCParticipant *>users;
    users.push_back(p);

    for(auto &usr: p->tagUsers)
    {
        users.push_back(&usr);
    }

    for( int i = 0; i < users.size(); ++i )
    {
        IZRCParticipant* treeUser = users[i];

        if( treeUser->type == ZRCParticipantUserType_Normal)
        {
            ZRCParticipant *user = dynamic_cast<ZRCParticipant *>(treeUser);
            cout << user->username << endl;
        }
        else
        {
            ZRCSmartTagUser *smartUser = static_cast<ZRCSmartTagUser *>(treeUser);
            cout << smartUser->name << endl;
        }
    }
}
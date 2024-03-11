//
//  ZRCUIZRStatusContext.hpp
//  ZRCUI
//
//  Created by Noah Gao on 2024/1/25.
//

#include <iostream>

using namespace std;

typedef int                                 CmmBool;
#define CmmTrue                              1
#define CmmFalse                             0

class IZRCUIParticipantContextMenuCapibility // Normal Meeting && (ZRInWebinar and UserInWebinar)
{
public:
    virtual CmmBool canLowerHand() = 0;
    virtual CmmBool canMuteOrUnmuteAudio() = 0;
    virtual CmmBool canMuteOrUnmuteVideo() = 0;
    virtual CmmBool canChat() = 0;
    virtual CmmBool canPinVideo() = 0;
    virtual CmmBool canPinNDI() = 0;
    virtual CmmBool canSpotlight() = 0;
    virtual CmmBool canFullRoomView() = 0;
    virtual CmmBool canCameraControl() = 0;
    virtual CmmBool canAllowRecording() = 0;
    virtual CmmBool canMakeHostOrCohost() = 0;
    virtual CmmBool canAllowAttendeeTalking() = 0;
    virtual CmmBool canChangeWebinarRole() = 0;
    virtual CmmBool canRename() = 0;
    virtual CmmBool canChangePanelistAppearance() = 0;
    virtual CmmBool canAllowToMultiPin() = 0;
    virtual CmmBool canAssignToTypeClosedCaption() = 0;
    virtual CmmBool canPutInSilentMode() = 0;
    virtual CmmBool canRemove() = 0;
    virtual CmmBool canShareMyPronouns() = 0;
    virtual CmmBool canShowMyKayPad() = 0;
};

//class IZRCUIZRStatusContext
//{
//    // virtual IZRCUIParticipantContextMenuCapibility* toOtherInBreakoutRoom() = 0;
//};

class IZRCUIZRInMeetingContext// : public IZRCUIZRStatusContext
{
public:
    virtual IZRCUIParticipantContextMenuCapibility* toOtherInMeeting() = 0;
};

class IZRCUIZRInWebinarContext// : public IZRCUIZRStatusContext
{
public:
    virtual IZRCUIParticipantContextMenuCapibility* toOtherInWebinar() = 0;
    virtual IZRCUIParticipantContextMenuCapibility* toOtherInBackstage() = 0;
};

class ZRCUIZRInMeetingContext: public IZRCUIZRInMeetingContext
{
    class ZRCUIParticipantContextMenuCapibility: private IZRCUIParticipantContextMenuCapibility // Normal Meeting && (ZRInWebinar and UserInWebinar)
    {
        virtual CmmBool canLowerHand() 
        { 
            cout << "canLowerHand in ZRCUIZRInMeetingContext " << endl;
            return CmmTrue; 
        }

        virtual CmmBool canMuteOrUnmuteAudio() { return CmmTrue; }
        virtual CmmBool canMuteOrUnmuteVideo() { return CmmTrue; }
        virtual CmmBool canChat() { return CmmTrue; }
        virtual CmmBool canPinVideo() { return CmmTrue; }
        virtual CmmBool canPinNDI() { return CmmTrue; }
        virtual CmmBool canSpotlight() { return CmmTrue; }
        virtual CmmBool canFullRoomView() { return CmmTrue; }
        virtual CmmBool canCameraControl() { return CmmTrue; }
        virtual CmmBool canAllowRecording() { return CmmTrue; }
        virtual CmmBool canMakeHostOrCohost() { return CmmTrue; }
        virtual CmmBool canAllowAttendeeTalking() { return CmmTrue; }
        virtual CmmBool canChangeWebinarRole() { return CmmTrue; }
        virtual CmmBool canRename() { return CmmTrue; }
        virtual CmmBool canChangePanelistAppearance() { return CmmTrue; }
        virtual CmmBool canAllowToMultiPin() { return CmmTrue; }
        virtual CmmBool canAssignToTypeClosedCaption() { return CmmTrue; }
        virtual CmmBool canPutInSilentMode() { return CmmTrue; }
        virtual CmmBool canRemove() { return CmmTrue; }
        virtual CmmBool canShareMyPronouns() { return CmmTrue; }
        virtual CmmBool canShowMyKayPad() { return CmmTrue; }
    };
    
    IZRCUIParticipantContextMenuCapibility* toOtherInMeeting() override
    {
        return (new ZRCUIZRInMeetingContext::ZRCUIParticipantContextMenuCapibility());
    }
};

class ZRCUIZRInWebinarContext: public IZRCUIZRInWebinarContext
{
    class OtherInBackstage: private IZRCUIParticipantContextMenuCapibility
    {
        CmmBool canLowerHand() override 
        { 
            cout << "canLowerHand in ZRCUIZRInWebinarContext.OtherInBackstage " << endl;
            return CmmFalse; 
        }
        CmmBool canMuteOrUnmuteAudio()  override { return CmmFalse; }
        CmmBool canMuteOrUnmuteVideo() override { return CmmFalse; }
        CmmBool canChat() override { return CmmTrue; }
        CmmBool canPinVideo() override { return CmmFalse; }
        CmmBool canPinNDI() override { return CmmFalse; }
        CmmBool canSpotlight() override { return CmmFalse; }
        CmmBool canFullRoomView() override { return CmmFalse; }
        CmmBool canCameraControl() override { return CmmFalse; }
        CmmBool canAllowRecording() override { return CmmFalse; }
        CmmBool canMakeHostOrCohost() override { return CmmTrue; }
        CmmBool canAllowAttendeeTalking() override { return CmmFalse; } // x
        CmmBool canChangeWebinarRole() override { return CmmTrue; }
        CmmBool canRename() override { return CmmTrue; }
        CmmBool canChangePanelistAppearance() override { return CmmFalse; }
        CmmBool canAllowToMultiPin() override { return CmmFalse; }
        CmmBool canAssignToTypeClosedCaption() override { return CmmFalse; }
        CmmBool canPutInSilentMode() override { return CmmFalse; }
        CmmBool canRemove() override { return CmmFalse; }
        CmmBool canShareMyPronouns() override { return CmmFalse; }  // X
        CmmBool canShowMyKayPad() override { return CmmFalse; } // X
    };
    
public:
    IZRCUIParticipantContextMenuCapibility* toOtherInWebinar() override
    {
        return (new ZRCUIZRInWebinarContext::OtherInBackstage());
    }
    
    IZRCUIParticipantContextMenuCapibility* toOtherInBackstage() override
    {
        return (new ZRCUIZRInWebinarContext::OtherInBackstage());
    }
};

class ZRCUIZRInBackstageContext: public IZRCUIZRInWebinarContext
{
public:
    class OtherInWebinar: public IZRCUIParticipantContextMenuCapibility
    {
        CmmBool canLowerHand() override { return CmmTrue; }
        CmmBool canMuteOrUnmuteAudio()  override { return CmmTrue; }
        CmmBool canMuteOrUnmuteVideo() override { return CmmTrue; }
        CmmBool canChat() override { return CmmTrue; }
        CmmBool canPinVideo() override { return CmmFalse; }
        CmmBool canPinNDI() override { return CmmTrue; }
        CmmBool canSpotlight() override { return CmmFalse; }
        CmmBool canFullRoomView() override { return CmmFalse; }
        CmmBool canCameraControl() override { return CmmFalse; }
        CmmBool canAllowRecording() override { return CmmTrue; }
        CmmBool canMakeHostOrCohost() override { return CmmTrue; }
        CmmBool canAllowAttendeeTalking() override { return CmmTrue; }
        CmmBool canChangeWebinarRole() override { return CmmTrue; }
        CmmBool canRename() override { return CmmTrue; }
        CmmBool canChangePanelistAppearance() override { return CmmTrue; }
        CmmBool canAllowToMultiPin() override { return CmmTrue; }
        CmmBool canAssignToTypeClosedCaption() override { return CmmTrue; }
        CmmBool canPutInSilentMode() override { return CmmTrue; }
        CmmBool canRemove() override { return CmmTrue; }
        CmmBool canShareMyPronouns() override { return CmmFalse; } // X
        CmmBool canShowMyKayPad() override { return CmmTrue; }
    };
    
    class OtherInBackstage: public IZRCUIParticipantContextMenuCapibility
    {
        CmmBool canLowerHand() override { return CmmFalse; }
        CmmBool canMuteOrUnmuteAudio()  override { return CmmTrue; } // userid in backstage
        CmmBool canMuteOrUnmuteVideo() override { return CmmTrue; } // userid in backstage
        CmmBool canChat() override { return CmmTrue; }
        CmmBool canPinVideo() override { return CmmTrue; } // userid in backstage
        CmmBool canPinNDI() override { return CmmFalse; }
        CmmBool canSpotlight() override { return CmmFalse; }
        CmmBool canFullRoomView() override { return CmmFalse; }
        CmmBool canCameraControl() override { return CmmFalse; }
        CmmBool canAllowRecording() override { return CmmFalse; }
        CmmBool canMakeHostOrCohost() override { return CmmTrue; }
        CmmBool canAllowAttendeeTalking() override { return CmmFalse; } // x
        CmmBool canChangeWebinarRole() override { return CmmTrue; }
        CmmBool canRename() override { return CmmTrue; }
        CmmBool canChangePanelistAppearance() override { return CmmTrue; }
        CmmBool canAllowToMultiPin() override { return CmmFalse; }
        CmmBool canAssignToTypeClosedCaption() override { return CmmFalse; }
        CmmBool canPutInSilentMode() override { return CmmFalse; }
        CmmBool canRemove() override { return CmmFalse; }
        CmmBool canShareMyPronouns() override { return CmmTrue; }
        CmmBool canShowMyKayPad() override { return CmmFalse; } // X
    };
    
public:
    IZRCUIParticipantContextMenuCapibility* toOtherInWebinar() override
    {
        return (new ZRCUIZRInBackstageContext::OtherInWebinar());
    }
    
    IZRCUIParticipantContextMenuCapibility* toOtherInBackstage() override
    {
        return (new ZRCUIZRInBackstageContext::OtherInBackstage());
    }
};

class ZRCWebinarBackstageUsersCapibilityBuilder
{
public:
    ZRCWebinarBackstageUsersCapibilityBuilder (CmmBool selfInWebinar, CmmBool otherInWebinar): selfInWebinar(selfInWebinar), otherInWebinar(otherInWebinar)
    {}
    
    IZRCUIParticipantContextMenuCapibility* build()
    {
        IZRCUIZRInWebinarContext *webinarContext = nullptr;
        if (selfInWebinar)
            webinarContext = new ZRCUIZRInWebinarContext();
         else
            webinarContext = new ZRCUIZRInBackstageContext();
        
        IZRCUIParticipantContextMenuCapibility *contextMenuCapibility = nullptr;
        if (otherInWebinar)
            contextMenuCapibility = webinarContext->toOtherInWebinar();
        else
            contextMenuCapibility = webinarContext->toOtherInBackstage();
        
        return contextMenuCapibility;
    };
    
private:
    CmmBool selfInWebinar;
    CmmBool otherInWebinar;
};

int main(int argc, char **argv)
{
    IZRCUIParticipantContextMenuCapibility *c = ZRCWebinarBackstageUsersCapibilityBuilder(CmmTrue, CmmFalse).build();
    cout << c->canAllowAttendeeTalking() << endl;

    ZRCUIZRInWebinarContext *inWebinar = new ZRCUIZRInWebinarContext();
    cout << inWebinar->toOtherInBackstage()->canLowerHand() << endl; 

}
//---------------------------------------------------------------------------

#ifndef SettingsH
#define SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TSets : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Strok;
        TLabel *Label2;
        TEdit *Shapes;
        TButton *Update;
        TLabel *Label3;
        TEdit *Speed;
        TButton *Help;
        TLabel *Label4;
        TEdit *Fig;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *PosX;
        TEdit *PosY;
        TEdit *PosWidth;
        TEdit *PosHeight;
        TButton *UpdParams;
        TButton *Visibled;
        TButton *Save;
        TButton *Load;
        TOpenDialog *OpenSave;
        TSaveDialog *SaveSave;
        TMemo *Data;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall HelpClick(TObject *Sender);
        void __fastcall UpdateClick(TObject *Sender);
        void __fastcall UpdParamsClick(TObject *Sender);
        void __fastcall VisibledClick(TObject *Sender);
        void __fastcall SaveClick(TObject *Sender);
        void __fastcall LoadClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSets(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSets *Sets;
//---------------------------------------------------------------------------
#endif

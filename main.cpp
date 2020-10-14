//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
int speed=1;
AnsiString move="";
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im EditorPro.exe");        
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StartupTimer(TObject *Sender)
{
        Startup->Enabled=false;
        MainForm->ClientWidth=800;
        MainForm->ClientHeight=600;
        for(int i=1;i<=100;i++)
        {
                ((TImage*)FindComponent("Shape" + IntToStr(i)))->Left=50;
                ((TImage*)FindComponent("Shape" + IntToStr(i)))->Top=0;
                ((TImage*)FindComponent("Shape" + IntToStr(i)))->Visible=false;
        }
        MainForm->AlphaBlendValue=255;
        MainForm->AlphaBlend=false;
        Sets->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_SHIFT)
        {
                speed=3;
        }
        else if(Key==VK_CONTROL)
        {
                Mover->Interval=100;
        }
        else if(Key==VK_LEFT)
        {
                move="left";
                Mover->Enabled=true;
        }
        else if(Key==VK_RIGHT)
        {
                move="right"; 
                Mover->Enabled=true;
        }
        else if(Key==VK_UP)
        {
                move="up";  
                Mover->Enabled=true;
        }
        else if(Key==VK_DOWN)
        {
                move="down";    
                Mover->Enabled=true;
        }
        else if(Key==83){
                move="down1";  
                Mover->Enabled=true;
        }
        else if(Key==87){
                move="up1"; 
                Mover->Enabled=true;
        }
        else if(Key==65){
                move="left1";
                Mover->Enabled=true;
        }
        else if(Key==68){
                move="right1";
                Mover->Enabled=true;
        }

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_SHIFT)
        {
                speed=1;
        }   
        else if(Key==VK_CONTROL)
        {
                Mover->Interval=1;
        }
        else if(Key==VK_LEFT)
        {
                move="";
                Mover->Enabled=false;
        }
        else if(Key==VK_RIGHT)
        {
                move="";  
                Mover->Enabled=false;
        }
        else if(Key==VK_UP)
        {
                move="";    
                Mover->Enabled=false;
        }
        else if(Key==VK_DOWN)
        {
                move="";     
                Mover->Enabled=false;
        }    
        else if(Key==83){
                move="";
                Mover->Enabled=false;
        }
        else if(Key==87){
                move="";
                Mover->Enabled=false;
        }
        else if(Key==65){
                move="";
                Mover->Enabled=false;
        }
        else if(Key==68){
                move="";
                Mover->Enabled=false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MoverTimer(TObject *Sender)
{
        AnsiString comp=Sets->Fig->Text;
        if(move=="right1")((TImage*)FindComponent(comp))->Width+=speed;
        else if(move=="left1")((TImage*)FindComponent(comp))->Width-=speed;
        else if(move=="down1")((TImage*)FindComponent(comp))->Height+=speed;
        else if(move=="up1")((TImage*)FindComponent(comp))->Height-=speed;
        else if(move=="up")((TImage*)FindComponent(comp))->Top-=speed;
        else if(move=="down")((TImage*)FindComponent(comp))->Top+=speed;
        else if(move=="left")((TImage*)FindComponent(comp))->Left-=speed;
        else if(move=="right")((TImage*)FindComponent(comp))->Left+=speed;
        Sets->PosX->Text=IntToStr(((TImage*)FindComponent(comp))->Left);
        Sets->PosY->Text=IntToStr(((TImage*)FindComponent(comp))->Top);
        Sets->PosWidth->Text=IntToStr(((TImage*)FindComponent(comp))->Width);
        Sets->PosHeight->Text=IntToStr(((TImage*)FindComponent(comp))->Height);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateTimer(TObject *Sender)
{
        Update->Enabled=false;
        AnsiString comp=Sets->Fig->Text;
        ((TImage*)FindComponent(comp))->Left=StrToInt(Sets->PosX->Text);
        ((TImage*)FindComponent(comp))->Top=StrToInt(Sets->PosY->Text);
        ((TImage*)FindComponent(comp))->Width=StrToInt(Sets->PosWidth->Text);
        ((TImage*)FindComponent(comp))->Height=StrToInt(Sets->PosHeight->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::UpdateSetsTimer(TObject *Sender)
{
        UpdateSets->Enabled=false;
        AnsiString comp=Sets->Fig->Text;
        Sets->PosX->Text=IntToStr(((TImage*)FindComponent(comp))->Left);
        Sets->PosY->Text=IntToStr(((TImage*)FindComponent(comp))->Top);
        Sets->PosWidth->Text=IntToStr(((TImage*)FindComponent(comp))->Width);
        Sets->PosHeight->Text=IntToStr(((TImage*)FindComponent(comp))->Height);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::VisTimer(TObject *Sender)
{
        Vis->Enabled=false;    
        AnsiString comp=Sets->Fig->Text;
        if(comp!="Green" && comp!="Red" && comp!="Win" && comp!="BG"){
        if(((TImage*)FindComponent(comp))->Visible==true)((TImage*)FindComponent(comp))->Visible=false;
        else
        {
        ((TImage*)FindComponent(comp))->Visible=true;
        if(((TImage*)FindComponent(comp))->Left==-666)((TImage*)FindComponent(comp))->Left=50;
        }  }
        else
        {
                Application->MessageBox("»змен€ть видимость можно только преп€дстви€м (Shape1, Shape2 и т. д. )","ErrorKolyaLoh!",MB_ICONERROR);
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaverTimer(TObject *Sender)
{
        Saver->Enabled=false;
        int shapes=0;
        int strokac=19;
        for(int i=1;i<=100;i++)
        {
                if(((TImage*)FindComponent("Shape"+IntToStr(i)))->Visible==true)
                {
                        shapes++;
                        Sets->Data->Lines->Strings[strokac]="Shape"+IntToStr(i);
                        Sets->Data->Lines->Strings[strokac+1]=((TImage*)FindComponent("Shape"+IntToStr(i)))->Left;
                        Sets->Data->Lines->Strings[strokac+2]=((TImage*)FindComponent("Shape"+IntToStr(i)))->Top;
                        Sets->Data->Lines->Strings[strokac+3]=((TImage*)FindComponent("Shape"+IntToStr(i)))->Width;
                        Sets->Data->Lines->Strings[strokac+4]=((TImage*)FindComponent("Shape"+IntToStr(i)))->Height;
                        strokac+=5;
                }
        }
        Sets->Data->Lines->Strings[0]=IntToStr(strokac);
        Sets->Data->Lines->Strings[1]=IntToStr(shapes);
        if(Sets->SaveSave->Execute())
        {
                Sets->Data->Lines->SaveToFile(Sets->SaveSave->FileName+".xlab");
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LoaderTimer(TObject *Sender)
{
        Loader->Enabled=false;
        int shapes=StrToInt(Sets->Data->Lines->Strings[1]);
        int stak=StrToInt(Sets->Data->Lines->Strings[0]);
        for(int i=shapes+1;i<=100;i++)
        {
                ((TImage*)FindComponent("Shape" + IntToStr(i)))->Left=50;
                ((TImage*)FindComponent("Shape" + IntToStr(i)))->Top=0;
                ((TImage*)FindComponent("Shape" + IntToStr(i)))->Visible=false;
        }
        for(int i=19;i<=stak;i+=5)
        {
                if(Sets->Data->Lines->Strings[i]=="Speed")
                {
                        Sets->Speed->Text=Sets->Data->Lines->Strings[i+1];
                        i+=2;
                }
                ((TImage*)FindComponent(Sets->Data->Lines->Strings[i]))->Visible=true;
                ((TImage*)FindComponent(Sets->Data->Lines->Strings[i]))->Left=StrToInt(Sets->Data->Lines->Strings[i+1]);
                ((TImage*)FindComponent(Sets->Data->Lines->Strings[i]))->Top=StrToInt(Sets->Data->Lines->Strings[i+2]);
                ((TImage*)FindComponent(Sets->Data->Lines->Strings[i]))->Width=StrToInt(Sets->Data->Lines->Strings[i+3]);
                ((TImage*)FindComponent(Sets->Data->Lines->Strings[i]))->Height=StrToInt(Sets->Data->Lines->Strings[i+4]);
        }
}
//---------------------------------------------------------------------------


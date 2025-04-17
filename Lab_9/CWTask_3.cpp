#include<iostream>
#include<vector>
using namespace std;

class PatientRecord{
    string name;
    string ID;
    string DOB ;
    vector<string> medicalhistory;
    vector<string> treatment ;
    vector<string> billinginfo ;
    friend class Doctor;
    friend class Account;
    void updatehistory(string data){
        medicalhistory.push_back(data);
        cout<<"Medical Record Updated"<<endl;
    }
    void addtreat(string treat){
        treatment.push_back(treat);
        cout<<"Treatment Record Updated"<<endl;
    }
    void addbilling(string bill){
        billinginfo.push_back(bill);
        cout<<"Bill Updated"<<endl;
    }
    public:
    void setvalues(string n , string id , string dob ){
        name=n; ID=id; DOB=dob;
    }
    string getpublicdata(){
        return name + "\n" +ID+"\n"+DOB+"\n" ;
    }
    vector<string> getmedicaldata(string role){
        if(role == "doctor"){
            return medicalhistory;
        }else{
            cout<<"Access Denied"<<endl;
            return {};
        }
    }
    vector<string> getbillinginfo(string role){
        if(role == "account"){
            return billinginfo;
        }else{
            cout<<"Access Denied"<<endl;
        }
    }
};

class Doctor{
    public:
    void updatehistory(PatientRecord& pr , string r){
        pr.updatehistory(r);
    }
    void updatetreatment(PatientRecord& pr , string t){
        pr.addtreat(t);
    }
    void viewrecord(PatientRecord& pr){
        auto record = pr.getmedicaldata("doctor");
        cout<<pr.name<<"'s Medical Data :"<<endl;
        for(const auto& entry : record){
            cout<<"- "<<entry<<endl;
        }
    }
};

class Account{
    public:
    void updatebilling(PatientRecord& pr , string b){
        pr.addbilling(b);
    }
    void viewbilling(PatientRecord& pr){
        auto bill = pr.getbillinginfo("account");
        cout<<pr.name<<"'s Billing Data : "<<endl;
        for(const auto& billing : bill){
            cout<< "- "<<billing<<endl;
        }
    }
};

class Receptionist{
    public:
    void viewbilling(PatientRecord& pr){
        cout<<"Receptionist Tring to Access Billing Information :"<<endl;
        pr.getbillinginfo("reception");
    }
    void viewrecord(PatientRecord& pr){
        cout<<"Receptionist Tring to Access Medical Information :"<<endl;
        pr.getmedicaldata("reception");
    }
};

int main(){
    PatientRecord patient1;
    patient1.setvalues("Tom" , "K240593" , "28 Feb 2021");

    Doctor D1;
    Account A1;
    Receptionist R1;

    D1.updatehistory(patient1 , "Viral");
    D1.updatetreatment(patient1 , "Paracetamol");
    D1.viewrecord(patient1);
}
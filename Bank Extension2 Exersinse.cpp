//
//
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <iomanip>
//
//using namespace std;
////Start
// const string ClientFile = "Clients.txt";
// const string UsersFile = "Users.txt";
// // Choices
// enum enMainMenu
// {
//	 eShowList = 1,
//	 eAddNewCleint = 2,
//	 eDeleteClient = 3,
//	 eUpdateClient = 4,
//	 eFindClient = 5,
//	 eTransactions = 6,
//	 eMangeUser = 7,
//	 eLogout = 8
// };
// enum enPermissions
// {
//	 PAll = -1,
//	 PClientList = 1,
//	 PAddNewCleint = 2,
//	 PDeleteClient = 4,
//	 PUpdateClient = 8,
//	 PFindClient = 16,
//	 PTransactions = 32,
//	 PMangeUser = 64,
//
// };
// enum enTransactions
// {
//	 Deposit = 1,
//	 Withdraw = 2,
//	 TotalBalances = 3,
//	 ReturnToManinMenu = 4
// };
// enum enManageUser
// {
//	 UserList = 1,
//	 AddUser = 2,
//	 DeleteUser = 3,
//	 UpdateUser = 4,
//	 FindUser = 5,
//	 ReturnToMainMenu = 6
// };
// //Structures
// struct stClient
// {
//	 string AccountNumber;
//	 string PinCode;
//	 string Name;
//	 string Phone;
//	 double AccountBalance;
//	 bool MarkForDelete = false;
// };
// struct stUser
// {
//	 string UserName;
//	 string Password;
//	 bool MarkForDeleteUser = false;
//	 int Permissions;
// };
// //Global Variable
// stUser CurrentUser;
// //Reading Functions
// string ReadAccountNumber()
// {
//	 string AccountNumber;
//	 cout << "Enter Account Number?"; cin >> AccountNumber;
//	 return AccountNumber;
// }
// string ReadingUsername()
// {
//	 string Username;
//	 cout << "Enter Username?"; cin >> Username;
//	 return Username;
// }
// string ReadingPassword()
// {
//	 string Password;
//	 cout << "Enter Username?"; cin >> Password;
//	 return Password;
// }
// int ReadPermissionsToSet()
// {
//	 int Permissions = 0;
//	 char answer = 'y';
//	 cout << "\nDo you want Full Access?Y/N?"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		 return -1;
//	 }
//
//	 cout << "\nDo you want Access To : \n";
//
//	 cout << "\nShow Client List?Y/N?"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		  Permissions += PClientList;
//	 }
//	 cout << "\nAdd New Client?Y/N?"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		  Permissions += PAddNewCleint;
//	 }
//	 cout << "\nDelete Client?Y/N?"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		  Permissions += PDeleteClient;
//	 }
//	 cout << "\nUpdate Client?Y/N?"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		  Permissions += PUpdateClient;
//	 }
//	 cout << "\nFind Client?Y/N?"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		  Permissions += PFindClient;
//	 }
//	 cout << "\nTransactions?Y/N?"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		  Permissions += PTransactions;
//	 }
//	 cout << "\nManage User?Y/N"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		  Permissions += PMangeUser;
//	 }
//	 return Permissions;
// }
// bool HasPermissions(enPermissions Permissions)
// {
//	 return ((CurrentUser.Permissions & Permissions) == Permissions);
// }
// // General Functions
// string Tabs(short NumberOfTabs)
// {
//	 string Tabs;
//	 for (short i = 0; i <= NumberOfTabs; i++)
//	 {
//		 Tabs += "\t";
//	 }
//	 return Tabs;
// }
// vector<string>SplitString(string S, string Delim)
// {
//	 vector<string>Vstring;
//	 string Sword;
//	 int Pos = 0;
//
//	 while ((Pos = S.find(Delim)) != string::npos)
//	 {
//		 Sword = S.substr(0, Pos);
//
//		 if (!Sword.empty())
//		 {
//			 Vstring.push_back(Sword);
//		 }
//		 S.erase(0, Pos + Delim.length());
//	 }
//	 if (!S.empty())
//	 {
//		 Vstring.push_back(S);
//	 }
//	 return Vstring;
// }
// void DeniedAccessMessage()
// {
//	 cout << "\nAccess Denied,Please Contact Your Admin...\n";
// }
// // Save and Load Functions (Client File)
//
// // Load Functions
// stClient ConvertClientLineToRecord(string S, string Delim = "#//#")
// {
//	 vector<string>Vstring = SplitString(S, Delim);
//
//	 stClient Client;
//
//	 Client.AccountNumber = Vstring[0];
//	 Client.PinCode = Vstring[1];
//	 Client.Name = Vstring[2];
//	 Client.Phone = Vstring[3];
//	 Client.AccountBalance = stod(Vstring[4]);
//
//	 return Client;
// }
// vector<stClient>LoadClientDataFromTheFile(string FileName)
// {
//	 vector<stClient>VClient;
//	 fstream MyFile;
//	 MyFile.open(FileName, ios::in);
//	 if (MyFile.is_open())
//	 {
//		 string Line; stClient Client;
//
//		 while (getline(MyFile, Line))
//		 {
//			 Client = ConvertClientLineToRecord(Line);
//
//			 VClient.push_back(Client);
//
//		 }
//		 MyFile.close();
//	 }
//	 return VClient;
// }
// // Save Functions
// 
// string ConvertClientRecordToLine(stClient Client, string Delim = "#//#")
// {
//	 string RecordLine;
//	 RecordLine += Client.AccountNumber + Delim;
//	 RecordLine += Client.PinCode + Delim;
//	 RecordLine += Client.Name + Delim;
//	 RecordLine += Client.Phone + Delim;
//	 RecordLine += to_string(Client.AccountBalance);
//	 return RecordLine;
// }
// vector<stClient>SaveClientDataToFile(string FileName)
// {
//	 vector<stClient>VClient = LoadClientDataFromTheFile(ClientFile);
//	 string SDataLine;
//	 fstream MyFile;
//	 MyFile.open(FileName, ios::out);
//	 if (MyFile.is_open())
//	 {
//		 for (stClient C : VClient)
//		 {
//			 SDataLine = ConvertClientRecordToLine(C);
//			 if (C.MarkForDelete == false)
//			 {
//				 MyFile << SDataLine << endl;
//			 }
//		 }
//		 MyFile.close();
//	 }
//	 vector<stClient>VClient = LoadClientDataFromTheFile(ClientFile);
//	 return VClient;
// }
// // Client Card
// void PrintClientCard(stClient Client)
// {
//	 cout << "\n----------------------------------------";
//	 cout << "\nAccount Number : " << Client.AccountNumber;
//	 cout << "\nPin Code       : " << Client.PinCode;
//	 cout << "\nClient Name    : " << Client.Name;
//	 cout << "\nClient Phone   : " << Client.Phone;
//	 cout << "\nAccount Balance: " << Client.AccountBalance;
//	 cout << "\n----------------------------------------\n";
// }
//// Show Client List
// void PrintClientRecord(stClient Client)
// {
//	 cout << "| " << left << setw(15) << Client.AccountNumber;
//	 cout << "| " << left << setw(10) << Client.PinCode;
//	 cout << "| " << left << setw(40) << Client.Name;
//	 cout << "| " << left << setw(12) << Client.Phone;
//	 cout << "| " << left << setw(12) << Client.AccountBalance;
// }
// void ShowClientList()
// {
//	 if (!HasPermissions(PClientList))
//	 {
//		 DeniedAccessMessage();
//		 return;
//	 }
//
//	 vector<stClient>VClient = LoadClientDataFromTheFile(ClientFile);
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 cout << Tabs(3) << "Clients List (" << VClient.size() << ") Client/s.\n";
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 cout << "| " << left << setw(15) << "Account Number";
//	 cout << "| " << left << setw(10) << "PinCode";
//	 cout << "| " << left << setw(40) << "Client Name";
//	 cout << "| " << left << setw(12) << "Client Phone";
//	 cout << "| " << left << setw(12) << "Account Balance";
//	 cout << "\n----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 if (VClient.size() == 0)
//		 cout << Tabs(3) << "No Client Available in the system!\n";
//	 else
//		 for (stClient C : VClient)
//		 {
//			 PrintClientRecord(C);
//			 cout << endl;
//		 }
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
// }
// // Total Balances
//
//  void PrintTotalBalancesRecord(stClient Client)
// {
//	 cout << "| " << left << setw(15) << Client.AccountNumber;
//	 cout << "| " << left << setw(40) << Client.Name;
//	 cout << "| " << left << setw(12) << Client.AccountBalance;
// }
// void ShowTotalBalancesList()
// {
//	 vector<stClient>VClient = LoadClientDataFromTheFile(ClientFile);
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 cout << Tabs(3) << "Client List (" << VClient.size() << ") Client/s.\n";
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 cout << "| " << left << setw(15) << "Account Number";
//	 cout << "| " << left << setw(40) << "Client Name";
//	 cout << "| " << left << setw(12) << "Account Balance";
//	 cout << "\n----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 double Balances = 0;
//	 if (VClient.size() == 0)
//		 cout << Tabs(2) << "No Client Available in the system!";
//	 else
//		 for (stClient C : VClient)
//		 {
//			 PrintTotalBalancesRecord(C);
//			 Balances += C.AccountBalance;
//			 cout << endl;
//		 }
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 cout << "\nTotal Balances : " << Balances << endl;
// }
//
// // Add Client
//
// bool IsClientExist(string FileName, string AccountNumber)
// {
//	 
//	 fstream MyFile;
//	 MyFile.open(FileName, ios::in);
//	 
//	 if (MyFile.is_open())
//	 {
//		 string Line; stClient Client;
//		 while (getline(MyFile, Line))
//		 {
//			 Client = ConvertClientLineToRecord(Line);
//			 if (Client.AccountNumber == AccountNumber)
//			 {
//				 MyFile.close();
//				 return true;
//			 }
//			 
//		 }
//		 MyFile.close();
//	 }
//	 return false;
// }
// stClient ReadClientData()
// {
//	 stClient Client;
//	 cout << "Enter Account Number?";
//	 getline(cin >> ws, Client.AccountNumber);
//	 while (IsClientExist(ClientFile, Client.AccountNumber))
//	 {
//		 cout << "\nAccount Number [" << Client.AccountNumber << "] Is already exist ,Enter Another Account Number?";
//		 getline(cin >> ws, Client.AccountNumber);
//	 }
//	 cout << "Enter Pin Code?"; getline(cin, Client.PinCode);
//	 cout << "Enter Client Name?"; getline(cin, Client.Name);
//	 cout << "Enter Client Phone?"; getline(cin, Client.Phone);
//	 cout << "Enter Account Balance?"; cin >> Client.AccountBalance;
//	 return Client;
// }
// void SaveClientRecordToFile(string FileName, string SDataLine)
// {
//	 fstream MyFile;
//
//	 MyFile.open(FileName, ios::out | ios::app);
//
//	 if (MyFile.is_open())
//	 {
//		 MyFile << SDataLine << endl;
//		 MyFile.close();
//	 }
// }
// void AddNewClient()
// {
//	 stClient Client = ReadClientData();
//	 SaveClientRecordToFile(ClientFile, ConvertClientRecordToLine(Client));
// }
// void AddMoreClients()
// {
//	 char AddMore = 'n';
//	 do
//	 {
//		 system("cls");
//		 cout << "\nAdd New Client: \n";
//
//		 AddNewClient();
//		 cout << "\nDo you want add More Client?Y/N?"; cin >> AddMore;
//	 } while (toupper(AddMore) == 'Y');
// }
// void ShowAddClientScreen()
// {
//	 if (!HasPermissions(PAddNewCleint))
//	 {
//		 DeniedAccessMessage();
//		 return;
//	 }
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Add Client Screen.\n";
//	 cout << "------------------------------------\n";
//	 AddMoreClients();
// }
// //Find and Mark For Delete
// bool FindClientByAccountNumber(string AccountNumber,  stClient& Client)
// {
//	 vector<stClient> VClient = LoadClientDataFromTheFile(ClientFile);
//	 for (stClient& C : VClient)
//	 {
//		 if (C.AccountNumber == AccountNumber)
//		 {
//			 Client = C;
//			 return true;
//		 }
//	 }
//	 return false;
// }
// bool MarkForDeleteClient(string AccountNumber)
// {
//	 vector<stClient>VClient = LoadClientDataFromTheFile(ClientFile);
//	 for (stClient& C : VClient)
//	 {
//		 if (C.AccountNumber == AccountNumber)
//		 {
//			 C.MarkForDelete = true;
//			 return true;
//		 }
//	 }
//	 return false;
// }
// //Delete Update And Find Client By Account Number Functions
//
// bool DeleteClientByAccountNumber(string AccountNumber)
// {
//	 char answer = 'y';
//	 stClient Client;
//	 if (FindClientByAccountNumber(AccountNumber,  Client))
//	 {
//		 PrintClientCard(Client);
//		 cout << "\nAre you sure you want delete this client?Y/N?"; cin >> answer;
//		 if (toupper(answer) == 'Y')
//		 {
//			 MarkForDeleteClient(Client.AccountNumber);
//			 SaveClientDataToFile(ClientFile);
//			 
//			 cout << "\nClient Deleted Successfully.\n";
//			 return true;
//
//		 }
//
//	 }
//	 else
//	 {
//		 cout << "\nAccount Number [" << AccountNumber << "] is not found";
//		 return false;
//	 }
// }
// stClient ChangeClientData(string AccountNumber)
// {
//	 stClient Client;
//	 Client.AccountNumber = AccountNumber;
//	 cout << "Enter Pin Code?"; getline(cin >> ws, Client.PinCode);
//	 cout << "Enter Client Name?"; getline(cin, Client.Name);
//	 cout << "Enter Client Phone?"; getline(cin, Client.Phone);
//	 cout << "Enter Account Balance?"; cin >> Client.AccountBalance;
//	 return Client;
//
// }
// bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& VClient)
// {
//	 char answer = 'y';
//	 stClient Client;
//	 if (FindClientByAccountNumber(AccountNumber, Client))
//	 {
//		 PrintClientCard(Client);
//		 cout << "\nAre you sure you want Update this Client?Y/N?"; cin >> answer;
//		 if (toupper(answer) == 'Y')
//		 {
//			 for (stClient& C : VClient)
//			 {
//				 if (C.AccountNumber == AccountNumber)
//				 {
//					 C = ChangeClientData(AccountNumber);
//					 break;
//				 } 
//				 
//			 }
//			 SaveClientDataToFile(ClientFile);
//			 cout << "Client Updated Successfully.";
//			 return true;
//		 }
//		 
//	 }
//	 else
//	 {
//		 cout << "\nAccount Number [" << AccountNumber << "] is not found";
//		 return false;
//	 }
// }
// // Deposite Function
// bool DpositeByClientAccountNumber(string AccountNumber, double Amount)
// {
//	 vector<stClient> VClient = LoadClientDataFromTheFile(ClientFile);
//	 char answer = 'n';
//	 cout << "Are you sure you want make this process?Y/N?"; cin >> answer;
//	 if (toupper(answer) == 'Y')
//	 {
//		 for (stClient& C : VClient)
//		 {
//			 if (C.AccountNumber == AccountNumber)
//			 {
//				 C.AccountBalance += Amount;
//				 cout << "\nSuccessfull Process New Balance is : " << C.AccountBalance << endl;
//				 SaveClientDataToFile(ClientFile);
//				 return true;
//			 }
//			 
//		 }
//		 
//	 }
//	 return false;
// }
// // All Show Screen Functions [Client]
// void ShowDeleteClientScreen()
// {
//	 if (!HasPermissions(PDeleteClient))
//	 {
//		 DeniedAccessMessage();
//		 return;
//	 }
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Delete Client Screen.\n";
//	 cout << "------------------------------------\n";
//	 string AccountNumber = ReadAccountNumber();
//	 
//	 
//
//	 DeleteClientByAccountNumber(AccountNumber);
//
// }
// void ShowUpdateClientScreen()
// {
//	 if (!HasPermissions(PUpdateClient))
//	 {
//		 DeniedAccessMessage();
//		 return;
//	 }
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Update Client Screen.\n";
//	 cout << "------------------------------------\n";
//	 string AccountNumber = ReadAccountNumber();
//	 vector<stClient>VClient = LoadClientDataFromTheFile(ClientFile);
//	 
//
//	 UpdateClientByAccountNumber(AccountNumber, VClient);
//
// }
// void ShowFindClientScreen()
// {
//	 if (!HasPermissions(PFindClient))
//	 {
//		 DeniedAccessMessage();
//		 return;
//	 }
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Find Client Screen.\n";
//	 cout << "------------------------------------\n";
//	 string AccountNumber = ReadAccountNumber();
//	 
//	 stClient Client;
//	 
//	 if (FindClientByAccountNumber(AccountNumber,Client))
//	 {
//		 PrintClientCard(Client);
//	 }
//	 else
//	 {
//		 cout << "\nAccount Number [" << AccountNumber << "] is not found";
//	 }
// }
// void ShowDepositScreen()
// {
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Deposit Screen.\n";
//	 cout << "------------------------------------\n";
//	 string AccountNumber = ReadAccountNumber();
//	 
//	 stClient Client;
//
//	 while (!FindClientByAccountNumber(AccountNumber, Client))
//	 {
//		 cout << "\nAccount Number [ " << AccountNumber << "] doesn't Exist,Enter Another Account Number?";
//		 AccountNumber = ReadAccountNumber();
//	 }
//	 PrintClientCard(Client);
//	 double Amount = 0;
//	 cout << "\nEnter Amount You want Deposit?"; cin >> Amount;
//	 DpositeByClientAccountNumber(AccountNumber, Amount);
// }
// void ShowWithdrwaScreen()
// {
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Withdraw Screen.\n";
//	 cout << "------------------------------------\n";
//	 string AccountNumber = ReadAccountNumber();
//	 
//	 stClient Client;
//	 
//
//	 while (!FindClientByAccountNumber(AccountNumber,Client))
//	 {
//		 cout << "\nAccount Number [ " << AccountNumber << "] doesn't Exist,Enter Another Account Number?";
//		 AccountNumber = ReadAccountNumber();
//	 }
//	 PrintClientCard(Client);
//	 double Amount = 0;
//	 cout << "\nEnter Amount You want Withdraw?"; cin >> Amount;
//	 while (Amount > Client.AccountBalance)
//	 {
//		 cout << "\nAmount Exceeds Balance you can withdraw up to : " << Client.AccountBalance;
//		 cout << "\nEnter another amount?"; cin >> Amount;
//	 }
//	 DpositeByClientAccountNumber(AccountNumber, -1 * Amount);
// }
// //*************************************************[User Funcions]*****************************************************
// // Load Functions
// stUser ConvertUserLineToRecord(string S, string Delim = "#//#")
// {
//	 vector<string>Vstring = SplitString(S, Delim);
//
//	 stUser User;
//
//	 User.UserName = Vstring[0];
//	 User.Password = Vstring[1];
//	 User.Permissions = stoi(Vstring[2]);
//
//	 return User;
// }
// vector<stUser>LoadUserDataFromTheFile(string FileName)
// {
//	 vector<stUser>VUser;
//	 fstream MyFile;
//	 MyFile.open(FileName, ios::in);
//	 if (MyFile.is_open())
//	 {
//		 string Line; stUser User;
//
//		 while (getline(MyFile, Line))
//		 {
//			 User = ConvertUserLineToRecord(Line);
//
//			 VUser.push_back(User);
//
//		 }
//		 MyFile.close();
//	 }
//	 return VUser;
// }
// // Save Functions
//
// string ConvertUserRecordToLine(stUser User, string Delim = "#//#")
// {
//	 string RecordLine;
//	 RecordLine += User.UserName + Delim;
//	 RecordLine += User.Password + Delim;
//	 RecordLine += to_string(User.Permissions);
//	 return RecordLine;
// }
// vector<stUser>SaveUserDataToFile(string FileName, vector<stUser>VUser)
// {
//	 string SDataLine;
//	 fstream MyFile;
//	 MyFile.open(FileName, ios::out);
//	 if (MyFile.is_open())
//	 {
//		 for (stUser U : VUser)
//		 {
//			 SDataLine = ConvertUserRecordToLine(U);
//			 if (U.MarkForDeleteUser == false)
//			 {
//				 MyFile << SDataLine << endl;
//			 }
//		 }
//		 MyFile.close();
//	 }
//	 return VUser;
// }
// // User Card
// void PrintUserCard(stUser User)
// {
//	 cout << "\n----------------------------------------";
//	 cout << "\nUsername   : " << User.UserName;
//	 cout << "\nPassword   : " << User.Password;
//	 cout << "\nPermissions: " << User.Permissions;
//	 cout << "\n----------------------------------------\n";
// }
// // Show User List
// void PrintUserRecord(stUser User)
// {
//	 cout << "| " << left << setw(15) << User.UserName;
//	 cout << "| " << left << setw(40) << User.Password;
//	 cout << "| " << left << setw(12) << User.Permissions;
// }
// void ShowUserList()
// {
//	 vector<stUser>VUser = LoadUserDataFromTheFile(UsersFile);
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 cout << Tabs(3) << "Users List (" << VUser.size() << ") User/s.\n";
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 cout << "| " << left << setw(15) << "Username";
//	 cout << "| " << left << setw(40) << "Password";
//	 cout << "| " << left << setw(12) << "Permissions";
//	 cout << "\n----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
//	 if (VUser.size() == 0)
//		 cout << "\nNo User Available in the system!\n";
//	 else
//		 for (stUser U : VUser)
//		 {
//			 PrintUserRecord(U);
//			 cout << endl;
//		 }
//	 cout << "----------------------------------------------------------------";
//	 cout << "-------------------------------------------------" << endl;
// }
//
// // Add User
//
// bool IsUserExist(string FileName, string Username)
// {
//	 vector<stUser>VUser;
//	 fstream MyFile;
//	 MyFile.open(FileName, ios::in);
//
//	 if (MyFile.is_open())
//	 {
//		 string Line; stUser User;
//		 while (getline(MyFile, Line))
//		 {
//			 User = ConvertUserLineToRecord(Line);
//			 if (User.UserName == Username)
//			 {
//				 return true;
//				 MyFile.close();
//			 }
//			 VUser.push_back(User);
//		 }
//		 MyFile.close();
//	 }
//	 return false;
// }
// stUser ReadUserData()
// {
//	 stUser User;
//	 cout << "Enter Username ?";
//	 getline(cin >> ws, User.UserName);
//	 if (IsUserExist(UsersFile, User.UserName))
//	 {
//		 cout << "\nUsername[" << User.UserName << "] Is already exist ,Enter Another Username?";
//		 getline(cin >> ws, User.UserName);
//	 }
//	 cout << "\nEnter Password?"; getline(cin, User.Password);
//	 
//	 User.Permissions = ReadPermissionsToSet();
//	 return User;
// }
// void SaveUserRecordToFile(string FileName, string SDataLine)
// {
//	 fstream MyFile;
//
//	 MyFile.open(FileName, ios::out | ios::app);
//
//	 if (MyFile.is_open())
//	 {
//		 MyFile << SDataLine << endl;
//		 MyFile.close();
//	 }
// }
// void AddNewUser()
// {
//	 stUser User = ReadUserData();
//	 SaveUserRecordToFile(UsersFile, ConvertUserRecordToLine(User));
// }
// void AddMoreUsers()
// {
//	 char AddMore = 'n';
//	 do
//	 {
//		 system("cls");
//		 cout << "\nAdd New User: \n";
//
//		 AddNewUser();
//		 cout << "\nDo you want add More User?Y/N?"; cin >> AddMore;
//	 } while (toupper(AddMore) == 'Y');
// }
// void ShowAddUserScreen()
// {
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Add User Screen.\n";
//	 cout << "------------------------------------\n";
//	 AddMoreUsers();
// }
// //Find and Mark For Delete
// bool FindUserByUsernameAndPassword(string Username,string Password,  stUser& User)
// {
//	 vector<stUser>VUser = LoadUserDataFromTheFile(UsersFile);
//	 for (stUser& U : VUser)
//	 {
//		 if (U.UserName == Username && U.Password == Password)
//		 {
//			 User = U;
//			 return true;
//		 }
//	 }
//	 return false;
// }
// bool LoadUserInfo(string Username, string Password)
// {
//	 
//	 
//	 return (FindUserByUsernameAndPassword(Username, Password, CurrentUser));
//	 
// }
// bool FindUserByUsername(string Username, vector<stUser>& VUser, stUser& User)
// {
//	 for (stUser& U : VUser)
//	 {
//		 if (U.UserName == Username)
//		 {
//			 User = U;
//			 return true;
//		 }
//	 }
//	 return false;
// }
// bool MarkForDeleteUser(string Username, vector<stUser>& VUser)
// {
//	 for (stUser& U : VUser)
//	 {
//		 if (U.UserName == Username)
//		 {
//			 U.MarkForDeleteUser = true;
//			 return true;
//		 }
//	 }
//	 return false;
// }
// //Delete Update And Find User By Username Functions
//
// bool DeleteUsertByUsername(string Username, vector<stUser>& VUser)
// {
//	 char answer = 'y';
//	 stUser User;
//	 if (FindUserByUsername(Username, VUser, User))
//	 {
//		 PrintUserCard(User);
//		 cout << "\nAre you sure you want delete this User?Y/N?"; cin >> answer;
//		 if (toupper(answer) == 'Y')
//		 {
//			  if (User.UserName == "Admin")
//			  {
//				  cout << "\nYou Can't Delete Admin User\n";
//				  return false;
//			  }
//			  else
//
//			  {
//				  MarkForDeleteUser(Username, VUser);
//				  SaveUserDataToFile(UsersFile, VUser);
//				  VUser = LoadUserDataFromTheFile(UsersFile);
//				  cout << "\nUser Deleted Successfully.\n";
//				  return true;
//			  }
//
//		 }
//
//	 }
//	 else
//	 {
//		 cout << "\nUsername [" << Username << "] is not found";
//		 return false;
//	 }
// }
// stUser ChangeUserData(string Username)
// {
//	 stUser User;
//	 User.UserName = Username;
//	 cout << "\nEnter Password?"; getline(cin >> ws, User.Password);
//	
//	 User.Permissions = ReadPermissionsToSet();
//	 return User;
//
// }
// bool UpdateUserByUsername(string Username, vector<stUser>& VUser)
// {
//	 char answer = 'y';
//	 stUser User;
//	 if (FindUserByUsername(Username, VUser, User))
//	 {
//		 PrintUserCard(User);
//		 cout << "\nAre you sure you want Update this User?Y/N?"; cin >> answer;
//		 if (toupper(answer) == 'Y')
//		 {
//			 for (stUser& U: VUser)
//			 {
//				 if (U.UserName == Username)
//				 {
//					 U = ChangeUserData(Username);
//					 break;
//				 }
//				 
//			 }
//			 SaveUserDataToFile(UsersFile, VUser);
//			 cout << "User Updated Successfully.";
//			 return true;
//		 }
//
//	 }
//	 else
//	 {
//		 cout << "\nUsername [" << Username << "] is not found";
//		 return false;
//	 }
// }
// 
// // All Show Screen Functions [User]
// void ShowDeleteUserScreen()
// {
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Delete User Screen.\n";
//	 cout << "------------------------------------\n";
//	 string Username = ReadingUsername();
//	 vector<stUser>VUser = LoadUserDataFromTheFile(UsersFile);
//	 
//
//	 DeleteUsertByUsername(Username, VUser);
//
// }
// void ShowUpdateUserScreen()
// {
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Update User Screen.\n";
//	 cout << "------------------------------------\n";
//	 string Username = ReadingUsername();
//	 vector<stUser>VUser = LoadUserDataFromTheFile(UsersFile);
//	 
//
//	 UpdateUserByUsername(Username, VUser);
//
// }
// void ShowFindUserScreen()
// {
//	 cout << "------------------------------------\n";
//	 cout << Tabs(1) << "Find User Screen.\n";
//	 cout << "------------------------------------\n";
//	 string Username = ReadingUsername();
//	 vector<stUser>VUser = LoadUserDataFromTheFile(UsersFile);
//	 stUser User;
//	
//	 if (FindUserByUsername(Username, VUser, User))
//	 {
//		 PrintUserCard(User);
//	 }
//	 else
//	 {
//		 cout << "\nUsername [" << Username << "] is not found";
//	 }
// }
// //******************************************************************************************************************************
// // Functions Definitinos
// void ShowMainMenu();
// void ShowTransactionsMenu();
// void ShowManageUsersMenu();
// void Login();
// // Transactions Menu
// void GoBackToTransactions()
// {
//	 cout << "\nPress any key to return back to Transactions menu......."; system("Pause>0");
//	 ShowTransactionsMenu();
// }
// short ChoseFormTransactionsMenu()
// {
//	 short Choice = 0;
//	 cout << "\nChose What Do you want to do From [1] to [4]?"; cin >> Choice;
//	 return Choice;
// }
// void PerformTransactionsMenuOptions(enTransactions Trans)
// {
//	 switch (Trans)
//	 {
//	 case Deposit:
//		 system("cls");
//		 ShowDepositScreen();
//		 GoBackToTransactions();
//		 break;
//
//	 case Withdraw:
//		 system("cls");
//		 ShowWithdrwaScreen();
//		 GoBackToTransactions();
//		 break;
//
//	 case TotalBalances:
//		 system("cls");
//		 ShowTotalBalancesList();
//		 GoBackToTransactions();
//		 break;
//
//	 case ReturnToManinMenu:
//		 system("cls");
//		 ShowMainMenu();
//		 break;
//
//	 }
// }
// void ShowTransactionsMenu()
// {
//	 if (!HasPermissions(PTransactions))
//	 {
//		 DeniedAccessMessage();
//		 return;
//	 }
//	 system("cls");
//	 cout << "===========================================================\n";
//	 cout << Tabs(2) << "Main Menu Screen\n";
//	 cout << "\n===========================================================\n";
//	 cout << Tabs(1) << "[1] Deposit.\n";
//	 cout << Tabs(1) << "[2] Withdraw.\n";
//	 cout << Tabs(1) << "[3] Total Balances.\n";
//	 cout << Tabs(1) << "[4] Return To Main Menu.\n";
//	 cout << "\n===========================================================\n";
//	 PerformTransactionsMenuOptions((enTransactions)ChoseFormTransactionsMenu());
// }
//
// // Mange Users Menu
//
// void GoBackToManageUsersMenu()
// {
//	 cout << "\nPress any key to return back to Mange Users menu......."; system("Pause>0");
//	 ShowManageUsersMenu();
// }
// short ChoseFormMangeUsersMenu()
// {
//	 short Choice = 0;
//	 cout << "\nChose What Do you want to do From [1] to [6]?"; cin >> Choice;
//	 return Choice;
// }
// void PerformManageUsersMenuOptions(enManageUser Mange)
// {
//	 switch (Mange)
//	 {
//	 case UserList:
//		 system("cls");
//		 ShowUserList();
//		 GoBackToManageUsersMenu();
//		 break;
//
//	 case AddUser:
//		 system("cls");
//		 ShowAddUserScreen();
//		 GoBackToManageUsersMenu();
//		 break;
//
//	 case DeleteUser:
//		 system("cls");
//		 ShowDeleteUserScreen();
//		 GoBackToManageUsersMenu();
//		 break;
//
//	 case UpdateUser:
//		 system("cls");
//		 ShowUpdateUserScreen();
//		 GoBackToManageUsersMenu();
//		 break;
//
//	 case FindUser:
//		 system("cls");
//		 ShowFindUserScreen();
//		 GoBackToManageUsersMenu();
//		 break;
//
//	 case ReturnToMainMenu:
//		 ShowMainMenu();
//		 break;
//
//	 }
// }
// void ShowManageUsersMenu()
// {
//	 if (!HasPermissions(PMangeUser))
//	 {
//		 DeniedAccessMessage();
//		 return;
//	 }
//	 system("cls");
//	 cout << "===========================================================\n";
//	 cout << Tabs(2) << "Manage Users Screen\n";
//	 cout << "\n===========================================================\n";
//	 cout << Tabs(1) << "[1] Show Users List.\n";
//	 cout << Tabs(1) << "[2] Add New User.\n";
//	 cout << Tabs(1) << "[3] Delete User.\n";
//	 cout << Tabs(1) << "[4] Update User.\n";
//	 cout << Tabs(1) << "[5] Find User.\n";
//	 cout << Tabs(1) << "[6] Return To Main Menu.\n";
//	 cout << "\n===========================================================\n";
//	 PerformManageUsersMenuOptions((enManageUser)ChoseFormMangeUsersMenu());
// }
//// Main Menu
// 
// void GoBackToMainMenu()
// {
//	 cout << "\nPress any key to return back to main menu......."; system("Pause>0");
//	 ShowMainMenu();
// }
// short ChoseFormMainMenu()
// {
//	 short Choice = 0;
//	 cout << "\nChose What Do you want to do From [1] to [8]?"; cin >> Choice;
//	 return Choice;
// }
// void PerformMainMenuOptions(enMainMenu Menu)
// {
//	 switch (Menu)
//	 {
//	 case eShowList:
//		 system("cls");
//		 ShowClientList();
//		 GoBackToMainMenu();
//		 break;
//
//	 case eAddNewCleint:
//		 system("cls");
//		 ShowAddClientScreen();
//		 GoBackToMainMenu();
//		 break;
//
//	 case eDeleteClient:
//		 system("cls");
//		 ShowDeleteClientScreen();
//		 GoBackToMainMenu();
//		 break;
//
//	 case eUpdateClient:
//		 system("cls");
//		 ShowUpdateClientScreen();
//		 GoBackToMainMenu();
//		 break;
//
//	 case eFindClient:
//		 system("cls");
//		 ShowFindClientScreen();
//		 GoBackToMainMenu();
//		 break;
//
//	 case eTransactions:
//		 system("cls");
//		 ShowTransactionsMenu();
//		 break;
//
//	 case eMangeUser:
//		 system("cls");
//		 ShowManageUsersMenu();
//		 GoBackToMainMenu();
//		 break;
//
//	 case eLogout:
//		 Login();
//		 break;
//		 
//	 }
// }
// void ShowMainMenu()
// {
//	 system("cls");
//	 cout << "================================================\n";
//	 cout << Tabs(2) << "Main Menu Screen\n";
//	 cout << "\n==============================================\n";
//	 cout << Tabs(1) << "[1] Show Client List.\n";
//	 cout << Tabs(1) << "[2] Add New Client.\n";
//	 cout << Tabs(1) << "[3] Delete Client.\n";
//	 cout << Tabs(1) << "[4] Update Client.\n";
//	 cout << Tabs(1) << "[5] Find Client.\n";
//	 cout << Tabs(1) << "[6] Transactions.\n";
//	 cout << Tabs(1) << "[7] Manage Users.\n";
//	 cout << Tabs(1) << "[8] Logout.\n";
//	 cout << "\n===============================================\n";
//	 PerformMainMenuOptions((enMainMenu)ChoseFormMainMenu());
// }
// // Login
// void Login()
// {
//	 string Username, Password;
//	 bool LoginFail = false;
//	 do
//	 {
//		 system("cls");
//		 cout << "------------------------------------\n";
//		 cout << Tabs(1) << "Login Screen.\n";
//		 cout << "------------------------------------\n";
//		
//		 if (LoginFail)
//		 {
//			 cout << "\nInvalid Username/Password!";
//		 }
//		 cout << endl;
//		 Username = ReadingUsername();
//		 Password = ReadingPassword();
//		 LoginFail = !LoadUserInfo(Username, Password);
//
//	 } while (LoginFail);
//	 ShowMainMenu();
// }
// int main()
// {
//	 Login();
//	 system("Pause>0");
//	 return 0;
//
// }


//#include <iostream>
//#include <vector>
//#include <iomanip>
//#include <fstream>
//#include <string>
//
//using namespace std;
////Files Names
//const string ClientFile = "Clients.txt";
//const string UsersFile = "Users.txt";
////choices
//enum enMainMenuOptions
//{
//    eShowClientsList = 1,
//    eAddNewClient = 2,
//    eDeleteClient = 3,
//    eUpdateClient = 4,
//    eFindClient = 5,
//    eTransaciotns = 6,
//    eMangeUsers = 7,
//    eLogout = 8
//};
//enum enTransactions
//{
//    Deposit = 1,
//    Withdraw = 2,
//    TotalBalances = 3,
//    ReturnToMainMenu = 4
//};
//enum enMangeUsers
//{
//    ShowList = 1,
//    AddUser = 2,
//    DeleteUser = 3,
//    UpdateUser = 4,
//    FindUser = 5,
//    MainMenu = 6
//};
//enum enPermissions
//{
//    PAll = -1,
//    PShowClientsList = 1,
//    PAddNewClient = 2,
//    PDeleteClient = 4,
//    PUpdateClient = 8,
//    PFindClient = 16,
//    PTransaciotns = 32,
//    PMangeUsers = 64,
//};
//
////My structurs
//struct stClient
//{
//    string AccountNumber;
//    string PinCode;
//    string Name;
//    string Phone;
//    double AccountBalance;
//    bool MarkForDeleteClient = false;
//
//};
//struct stUser
//{
//    string UserName;
//    string Password;
//    int Permissions;
//    bool MarkForDeleteUser = false;
//};
//// Global Variable
//stUser CurrentUser;
//
//// Functions Definitions
//void ShowTransactionsMenu();
//void ShowManageUsersMenu();
//void ShowMainMenu();
//void GoBackToMainMenu();
//void Login();
//
//// General Functions
//
//string Tabs(short NumberOfTabs)
//{
//    string Tabs;
//    for (short i = 0; i < NumberOfTabs; i++)
//    {
//        Tabs += "\t";
//
//    }
//    return Tabs;
//}
//
//vector<string>SplitString(string S, string Delim)
//{
//    vector<string>VString;
//    string Sword;
//    short Pos = 0;
//
//    while ((Pos = S.find(Delim)) != string::npos)
//    {
//        Sword = S.substr(0, Pos);
//        if (!S.empty())
//        {
//            VString.push_back(Sword);
//        }
//        S.erase(0, Pos + Delim.length());
//    }
//    if (!S.empty())
//    {
//        VString.push_back(S);
//    }
//    return VString;
//}
//void UserAccessDeniedMessage()
//{
//    cout << "\nAccess Denied! Please Contact you Admin...\n";
//}
//// Readding Functions
//string ReadAccountNumber()
//{
//    string AccountNumber;
//    cout << "\nEnter Account Number? "; cin >> AccountNumber;
//    return AccountNumber;
//}
//string ReadUserName()
//{
//    string UserName;
//    cout << "\nEnter Username? "; cin >> UserName;
//    return UserName;
//}
//string ReadPassword()
//{
//    string Password;
//    cout << "Enter Password? "; cin >> Password;
//    return Password;
//}
//int ReadPermissionsToSet()
//{
//    char Answer = 'y';
//    int Permissions = 0;
//    cout << "\nDo you want Full access?Y/N? "; cin >> Answer;
//    if (toupper(Answer) == 'Y')
//    {
//        return -1;
//            
//    }
//
//    cout << "\nDo you want access to : \n";
//
//
//    cout << "\nShow Client List?Y/N?"; cin >> Answer;
//    if (toupper(Answer) == 'Y')
//    {
//        Permissions += PShowClientsList;
//    }
//
//    cout << "\nAdd New Client?Y/N?"; cin >> Answer;
//    if (toupper(Answer) == 'Y')
//    {
//        Permissions += PAddNewClient;
//    }
//
//    cout << "\nDelete Client?Y/N?"; cin >> Answer;
//    if (toupper(Answer) == 'Y')
//    {
//        Permissions += PDeleteClient;
//    }
//
//    cout << "\nUpdate Client?Y/N?"; cin >> Answer;
//    if (toupper(Answer) == 'Y')
//    {
//        Permissions += PUpdateClient;
//    }
//
//    cout << "\nFind Client?Y/N?"; cin >> Answer;
//    if (toupper(Answer) == 'Y')
//    {
//        Permissions += PFindClient;
//    }
//
//    cout << "\nTransactionst?Y/N?"; cin >> Answer;
//    if (toupper(Answer) == 'Y')
//    {
//        Permissions += PTransaciotns;
//    }
//
//    cout << "\nManage Users?Y/N?"; cin >> Answer;
//    if (toupper(Answer) == 'Y')
//    {
//        Permissions += PMangeUsers;
//    }
//
//    return Permissions;
//}
//bool HasPermission(enPermissions Permissions)
//{
//    if (CurrentUser.Permissions == PAll)
//        return true;
//
//    if ((CurrentUser.Permissions & Permissions) == Permissions)
//        return true;
//    else
//        return false;
//}
////********************************[Clients Functions]****************************************
//
//// Load and Save Functions (Client)
//stClient ConverClientLineToRecord(string S, string Delim = "#//#")
//{
//    stClient Client;
//
//    vector<string>Vstring = SplitString(S, Delim);
//
//    Client.AccountNumber = Vstring[0];
//    Client.PinCode = Vstring[1];
//    Client.Name = Vstring[2];
//    Client.Phone = Vstring[3];
//    Client.AccountBalance = stod(Vstring[4]);
//
//    return Client;
//}
//vector<stClient>LoadClientDataFromFile(string FileName)
//{
//    vector<stClient>VClient;
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        string Line; stClient Client;
//        while (getline(MyFile, Line))
//        {
//            Client = ConverClientLineToRecord(Line);
//            VClient.push_back(Client);
//        }
//        MyFile.close();
//    }
//    return VClient;
//}
//// Save To File Functions (Client)
//string ConverClientRecordToLine(stClient Client, string Delim = "#//#")
//{
//    string RecordLine;
//    RecordLine += Client.AccountNumber + Delim;
//    RecordLine += Client.PinCode + Delim;
//    RecordLine += Client.Name + Delim;
//    RecordLine += Client.Phone + Delim;
//    RecordLine += to_string(Client.AccountBalance);
//    return RecordLine;
//}
//vector<stClient>SaveClientDataToFile(string FileName, vector<stClient>&VClient)
//{
//    fstream MyFile;
//    string SDataLine;
//    MyFile.open(FileName, ios::out);
//
//    if (MyFile.is_open())
//    {
//        for (stClient C : VClient)
//        {
//            SDataLine = ConverClientRecordToLine(C);
//            if (C.MarkForDeleteClient == false)
//            {
//                MyFile << SDataLine << endl;
//            }
//        }
//        MyFile.close();
//    }
//    return VClient;
//}
//// Show Client List Functions
//void PrintClientCard(stClient Client)
//{
//    cout << "\nThe Following are the Client Details";
//    cout << "\n----------------------------------------";
//    cout << "\nAccount Number : " << Client.AccountNumber;
//    cout << "\nPint Code      : " << Client.PinCode;
//    cout << "\nClient Name    : " << Client.Name;
//    cout << "\nClient Phone   : " << Client.Phone;
//    cout << "\nAccount Balance: " << Client.AccountBalance;
//    cout << "\n----------------------------------------\n";
//}
//void PrintClientRecord(stClient Client)
//{
//    cout << "| " << left << setw(15) << Client.AccountNumber;
//    cout << "| " << left << setw(10) << Client.PinCode;
//    cout << "| " << left << setw(40) << Client.Name;
//    cout << "| " << left << setw(12) << Client.Phone;
//    cout << "| " << left << setw(12) << Client.AccountBalance;
//    
//}
//
//void ShowClientList()
//{
//    if (!HasPermission(PShowClientsList))
//    {
//        UserAccessDeniedMessage();
//        GoBackToMainMenu();
//        return;
//    }
//
//    vector<stClient>VClient = LoadClientDataFromFile(ClientFile);
//    cout << "\n----------------------------------------------------------------";
//    cout << "-------------------------------------------" << endl;
//    cout << Tabs(4) << "Client List (" << VClient.size() << ")Client/s.\n";
//    cout << "\n----------------------------------------------------------------";
//    cout << "-------------------------------------------" << endl;
//    cout << "| " << left << setw(15) << "AccountNumber";
//    cout << "| " << left << setw(10) << "PinCode";
//    cout << "| " << left << setw(40) << "Name";
//    cout << "| " << left << setw(12) << "Phone";
//    cout << "| " << left << setw(12) << "AccountBalance";
//    cout << "\n----------------------------------------------------------------";
//    cout << "-------------------------------------------" << endl;
//    if (VClient.size() == 0)
//        cout << Tabs(3)<<"No Clients Available in the system.\n";
//    else 
//        for (stClient C : VClient)
//        {
//            PrintClientRecord(C);
//            cout << endl;
//        }
//    cout << "----------------------------------------------------------------";
//    cout << "-------------------------------------------" << endl;
//}
//
//// Total Balances
//void PrintTotalBalancesRecord(stClient Client)
//{
//    cout << "| " << left << setw(15) << Client.AccountNumber;
//    cout << "| " << left << setw(40) << Client.Name;
//    cout << "| " << left << setw(12) << Client.AccountBalance;
//
//}
//
//void ShowTotalBalancesList()
//{
//    vector<stClient>VClient = LoadClientDataFromFile(ClientFile);
//    cout << "\n----------------------------------------------------------------";
//    cout << "-------------------------------------------" << endl;
//    cout << Tabs(3) << "Clients List [" << VClient.size() << "] Client/s.";
//    cout << "\n----------------------------------------------------------------";
//    cout << "-------------------------------------------" << endl;
//    cout << "| " << left << setw(15) << "AccountNumber";
//    cout << "| " << left << setw(40) << "Name";
//    cout << "| " << left << setw(12) << "AccountBalance";
//    cout << "\n----------------------------------------------------------------";
//    cout << "-------------------------------------------" << endl;
//    double Balances = 0;
//    if (VClient.size() == 0)
//        cout << Tabs(3) << "No Clients Available in the system.\n";
//    else
//        for (stClient C : VClient)
//        {
//            PrintTotalBalancesRecord(C);
//            cout << endl;
//            Balances += C.AccountBalance;
//        }
//    cout << "\n----------------------------------------------------------------";
//    cout << "-------------------------------------------" << endl;
//    cout << Tabs(3) << "Total Balances : " << Balances << endl;
//}
//
//// Add New Client 
//
//bool IsClientExist(string FileName, string AccountNumber)
//{
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        string Line; stClient Client;
//        while (getline(MyFile, Line))
//        {
//            Client = ConverClientLineToRecord(Line);
//            if (Client.AccountNumber == AccountNumber)
//            {
//                MyFile.close();
//                return true;
//            }
//        }
//        MyFile.close();
//        
//    }
//    return false;
//}
//
//stClient ReadClientData()
//{
//    stClient Client;
//    cout << "Enter Account Number? "; getline(cin >> ws, Client.AccountNumber);
//    while (IsClientExist(ClientFile, Client.AccountNumber))
//    {
//        cout << "\nAccount Number [" << Client.AccountNumber << "] is already exist,";
//        cout << "\nEnter Another Account Number? "; getline(cin >> ws, Client.AccountNumber);
//    }
//
//    cout << "Enter Pin Code? "; getline(cin, Client.PinCode);
//    cout << "Enter Client Name? "; getline(cin, Client.Name);
//    cout << "Enter Client Phone? "; getline(cin, Client.Phone);
//    cout << "Enter Account Balance?"; cin >> Client.AccountBalance;
//    return Client;
//}
//void SaveClientRecordToFile(string FileName, string sDataLine)
//{
//    
//    fstream MyFile;
//    MyFile.open(FileName, ios::out | ios::app);
//
//    if (MyFile.is_open())
//    {
//        MyFile << sDataLine << endl;
//
//        MyFile.close();
//    }
//}
//void AddNewClient()
//{
//    stClient Client = ReadClientData();
//    SaveClientRecordToFile(ClientFile, ConverClientRecordToLine(Client));
//
//}
//void AddMoreClients()
//{
//    char AddMore = 'n';
//    do
//    {
//       
//        cout << "\nAdd New Client : \n";
//
//        AddNewClient();
//
//        cout << "\nDo you want to add another Client?Y/N?"; cin >> AddMore;
//
//    } while (toupper(AddMore) == 'Y');
//}
//// Find and Mark for delete Client
//
//bool FindClientByAccountNumber(string AccountNumber, vector<stClient>& VClient, stClient& Client)
//{
//    for (stClient& C : VClient)
//    {
//        if (C.AccountNumber == AccountNumber)
//        {
//            Client = C;
//            return true;
//           
//        }
//    }
//    return false;
//}
//bool MarkForDeleteClient(string AccountNumber, vector<stClient>& VClient)
//{
//    for (stClient& C : VClient)
//    {
//        if (C.AccountNumber == AccountNumber)
//        {
//            C.MarkForDeleteClient = true;
//            return true;
//        }
//    }
//    return false;
//}
//
//// Delete Update and Find Client Functions
//
//bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& VClient)
//{
//    char answer = 'y';
//    stClient Client;
//    if (FindClientByAccountNumber(AccountNumber, VClient, Client))
//    {
//        PrintClientCard(Client);
//        cout << "\nAre you sure you want delete this Client?Y/N? "; cin >> answer;
//        if (toupper(answer) == 'Y')
//        {
//            MarkForDeleteClient(AccountNumber, VClient);
//            SaveClientDataToFile(ClientFile, VClient);
//            VClient = LoadClientDataFromFile(ClientFile);
//            cout << "\nClient Deleted Successfully.";
//            return true;
//        }
//    }
//    else
//    {
//        cout << "\nAccount Number [" << AccountNumber << "] is not found!";
//        return false;
//    }
//}
//stClient ChangeClientData(string AccountNumber)
//{
//    stClient Client;
//    Client.AccountNumber = AccountNumber;
//    cout << "Enter Pin Code? "; getline(cin >> ws, Client.PinCode);
//    cout << "Enter Client Name? "; getline(cin, Client.Name);
//    cout << "Enter Client Phone? "; getline(cin, Client.Phone);
//    cout << "Enter Account Balance?"; cin >> Client.AccountBalance;
//    return Client;
//}
//bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& VClient)
//{
//    char answer = 'y';
//    stClient Client;
//    if (FindClientByAccountNumber(AccountNumber, VClient, Client))
//    {
//        PrintClientCard(Client);
//        cout << "\nAre you sure you want Update this Client?Y/N? "; cin >> answer;
//        if (toupper(answer) == 'Y')
//        {
//            for (stClient& C : VClient)
//            {
//                if (C.AccountNumber == AccountNumber)
//                {
//                    C = ChangeClientData(AccountNumber);
//                    break;
//                }
//            }
//            SaveClientDataToFile(ClientFile, VClient);
//            cout << "\nClient Updated Successfully.";
//            return true;
//        }
//    }
//    else
//    {
//        cout << "\nAccount Number [" << AccountNumber << "] is not found!";
//        return false;
//    }
//}
//// Deposit Function
//bool DepositByAccountNumber(string AccountNumber, double Amount, vector<stClient>& VClient)
//{
//    char Ans = 'y';
//    cout << "\nAre you sure you want do this process?Y/N?"; cin >> Ans;
//    if (toupper(Ans) == 'Y')
//    {
//        for (stClient& C : VClient)
//        {
//            if (C.AccountNumber == AccountNumber)
//            {
//                C.AccountBalance += Amount;
//                SaveClientDataToFile(ClientFile, VClient);
//                cout << "\nSuccessFull Process New Balance is : " << C.AccountBalance << endl;
//                return true;
//            }
//
//        }
//       
//    }
//    return false;
//}
//// All Show Functions
//void ShowAddClientScreen()
//{
//    if (!HasPermission(PAddNewClient))
//    {
//        UserAccessDeniedMessage();
//        return;
//    }
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Add Client Screen.";
//    cout << "\n----------------------------------------\n";
//    AddMoreClients();
//}
//void ShowDeleteClientScreen()
//{
//    if (!HasPermission(PDeleteClient))
//    {
//        UserAccessDeniedMessage();
//        return;
//    }
//    
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Delete Client Screen.";
//    cout << "\n----------------------------------------\n";
//    string AccountNumber = ReadAccountNumber();
//    vector<stClient>VClient = LoadClientDataFromFile(ClientFile);
//   
//    DeleteClientByAccountNumber(AccountNumber, VClient);
//}
//void ShowUpdateClientScreen()
//{
//    if (!HasPermission(PUpdateClient))
//    {
//        UserAccessDeniedMessage();
//        return;
//    }
//
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Update Client Screen.";
//    cout << "\n----------------------------------------\n";
//    string AccountNumber = ReadAccountNumber();
//    vector<stClient>VClient = LoadClientDataFromFile(ClientFile);
//
//    UpdateClientByAccountNumber(AccountNumber, VClient);
//}
//void ShowFindClientScreen()
//{
//    if (!HasPermission(PFindClient))
//    {
//        UserAccessDeniedMessage();
//        return;
//    }
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Find Client Screen.";
//    cout << "\n----------------------------------------\n";
//    string AccountNumber = ReadAccountNumber();
//    vector<stClient>VClient = LoadClientDataFromFile(ClientFile);
//    stClient Client;
//    if (FindClientByAccountNumber(AccountNumber, VClient, Client))
//    {
//        PrintClientCard(Client);
//    }
//    else
//    {
//        cout << "\nAccount Number [" << AccountNumber << "] is not found!";
//    }
//}
//void ShowDepositScreen()
//{
//
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Deposit Screen.";
//    cout << "\n----------------------------------------\n";
//    string AccountNumber = ReadAccountNumber();
//    vector<stClient>VClient = LoadClientDataFromFile(ClientFile);
//    stClient Client;
//    while (!FindClientByAccountNumber(AccountNumber, VClient, Client))
//    {
//        cout << "Account Number" << AccountNumber << "does not exist";
//        AccountNumber = ReadAccountNumber();
//    }
//    PrintClientCard(Client);
//    double Amount = 0;
//    cout << "\nEnter Amount You Want Deposit : "; cin >> Amount;
//    DepositByAccountNumber(AccountNumber, Amount, VClient);
//   
//}
//void ShowWithdrawScreen()
//{
//
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Withdraw Screen.";
//    cout << "\n----------------------------------------\n";
//    string AccountNumber = ReadAccountNumber();
//    vector<stClient>VClient = LoadClientDataFromFile(ClientFile);
//    stClient Client;
//    while (!FindClientByAccountNumber(AccountNumber, VClient, Client))
//    {
//        cout << "Account Number" << AccountNumber << "does not exist";
//        AccountNumber = ReadAccountNumber();
//    }
//    PrintClientCard(Client);
//    double Amount = 0;
//    cout << "\nEnter Amount You Want Withdraw : "; cin >> Amount;
//    while (Amount > Client.AccountBalance)
//    {
//        cout << "\n\nAmount Exceeds Balance you can withdraw up to : " << Client.AccountBalance;
//        cout << "\n\nEnte Another Amount : "; cin >> Amount;
//    }
//    DepositByAccountNumber(AccountNumber, -1 * Amount, VClient);
//}
////********************************[Users Functions]****************************************
//
//// Load and Save Functions (User)
//stUser ConverUserLineToRecord(string S, string Delim = "#//#")
//{
//    stUser User;
//
//    vector<string>Vstring = SplitString(S, Delim);
//
//    User.UserName = Vstring[0];
//    User.Password = Vstring[1];
//    User.Permissions = stoi(Vstring[2]);
//
//    return User;
//}
//vector<stUser>LoadUserDataFromFile(string FileName)
//{
//    vector<stUser>VUser;
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        string Line; stUser User;
//        while (getline(MyFile, Line))
//        {
//            User = ConverUserLineToRecord(Line);
//            VUser.push_back(User);
//        }
//        MyFile.close();
//    }
//    return VUser;
//}
//// Save To File Functions (Client)
//string ConverUserRecordToLine(stUser User, string Delim = "#//#")
//{
//    string RecordLine;
//    RecordLine += User.UserName + Delim;
//    RecordLine += User.Password + Delim;
//    RecordLine += to_string(User.Permissions);
//    return RecordLine;
//}
//vector<stUser>SaveUserDataToFile(string FileName, vector<stUser>& VUser)
//{
//    fstream MyFile;
//    string SDataLine;
//    MyFile.open(FileName, ios::out);
//
//    if (MyFile.is_open())
//    {
//        for (stUser U : VUser)
//        {
//            SDataLine = ConverUserRecordToLine(U);
//            if (U.MarkForDeleteUser == false)
//            {
//                MyFile << SDataLine << endl;
//            }
//        }
//        MyFile.close();
//    }
//    return VUser;
//}
//// Show Client List Functions
//void PrintUserCard(stUser User)
//{
//    cout << "\nThe Following are the user details.";
//    cout << "\n----------------------------------------";
//    cout << "\nUsername   : " << User.UserName;
//    cout << "\nPassword   : " << User.Password;
//    cout << "\nPermissions: " << User.Permissions;
//    cout << "\n----------------------------------------\n";
//}
//void PrintUserRecord(stUser User)
//{
//    cout << "| " << left << setw(15) << User.UserName;
//    cout << "| " << left << setw(40) << User.Password;
//    cout << "| " << left << setw(12) << User.Permissions;
//}
//
//void ShowUsersList()
//{
//    vector<stUser>VUser = LoadUserDataFromFile(UsersFile);
//    cout << "\n---------------------------------------------------------";
//    cout << "-----------------------------------------------" << endl;
//    cout << "Users List [" << VUser.size() << "] User/s.";
//    cout << "\n---------------------------------------------------------";
//    cout << "-----------------------------------------------" << endl;
//    cout << "| " << left << setw(15) << "UserName";
//    cout << "| " << left << setw(40) << "Password";
//    cout << "| " << left << setw(12) << "Permissios";
//    cout << "\n---------------------------------------------------------";
//    cout << "-----------------------------------------------" << endl;
//    if (VUser.size() == 0)
//        cout << "\nNo Users Available in the system.\n";
//    else
//        for (stUser U : VUser)
//        {
//            PrintUserRecord(U);
//            cout << endl;
//        }
//    cout << "\n---------------------------------------------------------";
//    cout << "-----------------------------------------------" << endl;
//}
//
//// Add New User 
//
//bool IsUserExist(string FileName, string UserName)
//{
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        string Line; stUser User;
//        while (getline(MyFile, Line))
//        {
//            User = ConverUserLineToRecord(Line);
//            if (User.UserName == UserName)
//            {
//                MyFile.close();
//                return true;
//                
//            }
//        }
//        
//        MyFile.close();
//    }
//    return false;
//
//}
//
//stUser ReadUserData()
//{
//    stUser User;
//    cout << "Enter UserName? "; getline(cin >> ws, User.UserName);
//    while (IsUserExist(UsersFile, User.UserName))
//    {
//        cout << "\nUserName [" << User.UserName << "] is already exist,";
//        cout << "\nEnter Another UserName? "; getline(cin >> ws, User.UserName);
//    }
//
//    cout << "Enter Password? "; getline(cin, User.Password);
//
//    User.Permissions = ReadPermissionsToSet();
//    return User;
//}
//void SaveUserRecordToFile(string FileName, string sDataLine)
//{
//
//    fstream MyFile;
//    MyFile.open(FileName, ios::out | ios::app);
//
//    if (MyFile.is_open())
//    {
//        MyFile << sDataLine << endl;
//
//        MyFile.close();
//    }
//}
//void AddNewUser()
//{
//    stUser User = ReadUserData();
//    SaveUserRecordToFile(UsersFile, ConverUserRecordToLine(User));
//
//}
//void AddMoreUsers()
//{
//    char AddMore = 'n';
//    do
//    {
//       
//        cout << "\nAdd New User : \n";
//
//        AddNewUser();
//
//        cout << "\nDo you want to add another User?Y/N?"; cin >> AddMore;
//
//    } while (toupper(AddMore) == 'Y');
//}
//// Find and Mark for delete User
//
//bool FindUserByUserNameandPassword(string Username,string Password,stUser& User)
//{
//    vector<stUser> VUser = LoadUserDataFromFile(UsersFile);
//    for (stUser& U : VUser)
//    {
//        if (U.UserName == Username && U.Password == Password)
//        {
//            User = U;
//            return true;
//            
//        }
//    }
//    return false;
//}
//bool IsLoginSuccessful(string Username,string Password)
//{
//    
//    return (FindUserByUserNameandPassword(Username, Password,CurrentUser));
//}
//bool FindUserByUserName(string Username, vector<stUser>& VUser, stUser& User)
//{
//    for (stUser& U : VUser)
//    {
//        if (U.UserName == Username)
//        {
//            User = U;
//            return true;
//           
//        }
//    }
//    return false;
//}
//bool MarkForDeleteUser(string Username, vector<stUser>& VUser)
//{
//    for (stUser& U : VUser)
//    {
//        if (U.UserName == Username)
//        {
//            U.MarkForDeleteUser = true;
//            return true;
//        }
//    }
//    return false;
//}
//
//// Delete Update and Find Client Functions
//
//bool DeleteUserByUserName(string UserName, vector<stUser>& VUser)
//{
//    char answer = 'y';
//    stUser User;
//    if (FindUserByUserName(UserName, VUser, User))
//    {
//        PrintUserCard(User);
//        cout << "\nAre you sure you want delete this User?Y/N? "; cin >> answer;
//        if (toupper(answer) == 'Y')
//        {
//            if (User.UserName == "Admin")
//            {
//                cout << "\nYou can't Delete Admin User!\n";
//                return false;
//            }
//            else
//            {
//                MarkForDeleteUser(UserName, VUser);
//                SaveUserDataToFile(UsersFile, VUser);
//                VUser = LoadUserDataFromFile(UsersFile);
//                cout << "\nUser Deleted Successfully.";
//                return true;
//            }
//        }
//    }
//    else
//    {
//        cout << "\nUsername [" << UserName << "] is not found!";
//        return false;
//    }
//}
//stUser ChangeUserData(string Username)
//{
//    stUser User;
//    User.UserName = Username;
//    cout << "Enter Password? "; getline(cin >> ws, User.Password);
//    User.Permissions = ReadPermissionsToSet();
//    return User;
//}
//bool UpdateUserByUserName(string UserName, vector<stUser>& VUser)
//{
//    char answer = 'y';
//    stUser User;
//    if (FindUserByUserName(UserName, VUser, User))
//    {
//        PrintUserCard(User);
//        cout << "\nAre you sure you want Update this User?Y/N? "; cin >> answer;
//        if (toupper(answer) == 'Y')
//        {
//            for (stUser& U : VUser)
//            {
//                if (U.UserName == UserName)
//                {
//                    U = ChangeUserData(UserName);
//                    break;
//                }
//            }
//            SaveUserDataToFile(UsersFile, VUser);
//            cout << "\nUser Updated Successfully.";
//            return true;
//        }
//    }
//    else
//    {
//        cout << "\nUsername [" << UserName << "] is not found!";
//        return false;
//    }
//}
//// All Show Functions
//void ShowAddUserScreen()
//{
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Add User Screen.";
//    cout << "\n----------------------------------------\n";
//    AddMoreUsers();
//}
//void ShowDeleteUserScreen()
//{
//
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "User Client Screen.";
//    cout << "\n----------------------------------------\n";
//    string UserName = ReadUserName();
//    vector<stUser>VUser = LoadUserDataFromFile(UsersFile);
//
//    DeleteUserByUserName(UserName, VUser);
//}
//void ShowUpdateUserScreen()
//{
//
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Update User Screen.";
//    cout << "\n----------------------------------------\n";
//    string UserName = ReadUserName();
//    vector<stUser>VUser = LoadUserDataFromFile(UsersFile);
//
//    UpdateUserByUserName(UserName, VUser); 
//   
//}
//void ShowFindUserScreen()
//{
//
//    cout << "----------------------------------------\n";
//    cout << Tabs(1) << "Find User Screen.";
//    cout << "\n----------------------------------------\n";
//    string UserName = ReadUserName();
//    vector<stUser>VUser = LoadUserDataFromFile(UsersFile);
//    stUser User;
//    if (FindUserByUserName(UserName, VUser, User))
//    {
//        PrintUserCard(User);
//    }
//    else
//    {
//        cout << "\nUsername [" << UserName << "] is not found!";
//    }
//}
//
////***************************************************************************
//
////All Menues
//
//// Transactions Menu
//void GoBackToTransactionsMenu()
//{
//    cout << "\nPress Any Key To Go Back To Transactions Menu.....";
//    system("Pause>0");
//    ShowTransactionsMenu();
//}
//int ChoseFromTransactionsMenu()
//{
//    int Choice;
//    cout << "\nChose What Do You Want To do From [1] To [4] ? "; cin >> Choice;
//    return Choice;
//}
//void PerformTransactionsMenuOptions(enTransactions Trans)
//{
//    switch (Trans)
//    {
//    case Deposit:
//        system("cls");
//        ShowDepositScreen();
//        GoBackToTransactionsMenu();
//        break;
//
//    case Withdraw:
//        system("cls");
//        ShowWithdrawScreen();
//        GoBackToTransactionsMenu();
//        break;
//
//    case TotalBalances:
//        system("cls");
//        ShowTotalBalancesList();
//        GoBackToTransactionsMenu();
//        break;
//
//    case ReturnToMainMenu:
//        ShowMainMenu();
//        break;
//
//    }
//}
//void ShowTransactionsMenu()
//{
//    if (!HasPermission(PTransaciotns))
//    {
//        UserAccessDeniedMessage();
//        GoBackToMainMenu();
//        return;
//    }
//    system("cls");
//    cout << "=======================================================\n";
//    cout << Tabs(2) << "Transactions Menu Screen.\n";
//    cout << "=======================================================\n";
//    cout << Tabs(1) << "[1] Deposit.\n";
//    cout << Tabs(1) << "[2] Withdraw.\n";
//    cout << Tabs(1) << "[3] Total Balances.\n";
//    cout << Tabs(1) << "[4] Go Back To Main Menu.\n";
//    cout << "=======================================================\n";
//    PerformTransactionsMenuOptions((enTransactions)ChoseFromTransactionsMenu());
//}
//
//// Manage User Menu
//void GoBackToManageUsersMenu()
//{
//    cout << "\nPress Any Key To Go Back To Manage Users Menu.....";
//    system("Pause>0");
//    ShowManageUsersMenu();
//}
//int ChoseFromManageUsersMenu()
//{
//    int Choice;
//    cout << "\nChose What Do You Want To do From [1] To [6] ? "; cin >> Choice;
//    return Choice;
//}
//void PerformManageUsersMenuOptions(enMangeUsers Manage)
//{
//    switch (Manage)
//    {
//    case ShowList:
//        system("cls");
//        ShowUsersList();
//        GoBackToManageUsersMenu();
//        break;
//
//    case AddUser:
//        system("cls");
//        ShowAddUserScreen();
//        GoBackToManageUsersMenu();
//        break;
//
//    case DeleteUser:
//        system("cls");
//        ShowDeleteUserScreen();
//        GoBackToManageUsersMenu();
//        break;
//
//    case UpdateUser:
//        system("cls");
//        ShowUpdateUserScreen();
//        GoBackToManageUsersMenu();
//        break;
//
//    case FindUser:
//        system("cls");
//        ShowFindUserScreen();
//        GoBackToManageUsersMenu();
//        break;
//
//    case MainMenu:
//        ShowMainMenu();
//        break;
//
//    }
//}
//void ShowManageUsersMenu()
//{
//    if (!HasPermission(PMangeUsers))
//    {
//        UserAccessDeniedMessage();
//        GoBackToMainMenu();
//        return;
//    }
//    system("cls");
//    cout << "=======================================================\n";
//    cout << Tabs(2) << "Manage Users Menu Screen.\n";
//    cout << "=======================================================\n";
//    cout << Tabs(1) << "[1] Show Users List.\n";
//    cout << Tabs(1) << "[2] Add New User.\n";
//    cout << Tabs(1) << "[3] Delete User.\n";
//    cout << Tabs(1) << "[4] Update User.\n";
//    cout << Tabs(1) << "[5] Find User.\n";
//    cout << Tabs(1) << "[6] Go Back To Main Menu.\n";
//    cout << "=======================================================\n";
//    PerformManageUsersMenuOptions((enMangeUsers)ChoseFromManageUsersMenu());
//}
//// Main Menu
//void GoBackToMainMenu()
//{
//    cout << "\n\nPress Any Key To Go Back To Main Menu.....";
//    system("Pause>0");
//    ShowMainMenu();
//}
//int ChoseFromMainMenu()
//{
//    int Choice;
//    cout << "\nChose What Do You Want To do From [1] To [8] ? "; cin >> Choice;
//    return Choice;
//}
//void PerformMainMenuOptions(enMainMenuOptions Menu)
//{
//    switch (Menu)
//    {
//    case eShowClientsList:
//        system("cls");
//        ShowClientList();
//        GoBackToMainMenu();
//        break;
//
//    case eAddNewClient:
//        system("cls");
//        ShowAddClientScreen();
//        GoBackToMainMenu();
//        break;
//
//    case eDeleteClient:
//        system("cls");
//        ShowDeleteClientScreen();
//        GoBackToMainMenu();
//        break;
//
//    case eUpdateClient:
//        system("cls");
//        ShowUpdateClientScreen();
//        GoBackToMainMenu();
//        break;
//
//    case eFindClient:
//        system("cls");
//        ShowFindClientScreen();
//        GoBackToMainMenu();
//        break;
//
//    case eTransaciotns:
//        system("cls");
//        ShowTransactionsMenu();
//        break;
//
//    case eMangeUsers:
//        system("cls");
//        ShowManageUsersMenu();
//        break;
//
//    case eLogout:
//        Login();
//        break;
//    }
//}
//void ShowMainMenu()
//{
//    system("cls");
//    cout << "=======================================================\n";
//    cout << Tabs(2) << "Main Menu Screen.\n";
//    cout << "=======================================================\n";
//    cout << Tabs(1) << "[1] Show Client List.\n";
//    cout << Tabs(1) << "[2] Add New Client.\n";
//    cout << Tabs(1) << "[3] Delete Client.\n";
//    cout << Tabs(1) << "[4] Update Client.\n";
//    cout << Tabs(1) << "[5] Find Client.\n";
//    cout << Tabs(1) << "[6] Transactions.\n";
//    cout << Tabs(1) << "[7] Manage Users .\n";
//    cout << Tabs(1) << "[8] Logout.\n";
//    cout << "=======================================================\n";
//    PerformMainMenuOptions((enMainMenuOptions)ChoseFromMainMenu());
//}
//
//
//void Login()
//{
//    bool LoginFail = false;
//    string Username, Password;
//    do
//    {
//        system("cls");
//        cout << "----------------------------------------\n";
//        cout << Tabs(1) << "Login Screen.";
//        cout << "\n----------------------------------------\n";
//        
//        if (LoginFail)
//        {
//            cout << "Invalid Username/Password!";
//        }
//
//        Username = ReadUserName();
//        Password = ReadPassword();
//
//        LoginFail = !IsLoginSuccessful(Username, Password);
//
//    } while (LoginFail);
//    ShowMainMenu();
//}
//int main()
//{
//    Login();
//    system("Pause>0");
//    return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
// Files names

const string ClientsFile = "Clients.txt";
const string UsersFile = "Users.txt";

// Choices 
enum enMainMenuOptions { eClientsList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eTransactions = 6, eMangeUser = 7, eLogout = 8 };

enum enTransactionsMenu { Deposit = 1, Withdraw = 2, TotalBalances = 3, ReturnToMainMenu = 4 };

enum enManageUserMenu { UsersList = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, MainMenu };

enum enPermissions { PAll = -1, PClientList = 1, PAddNewClient = 2, PDeleteClient = 4, PUpdateClient = 8, PFindClient = 16, PTransactions = 32, PMangeUsers = 64 };

// Structure

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkToDeleteClient = false;
};

struct stUser
{
	string Username;
	string Password;
	int Permissions;
	bool MarkToDeleteUser = false;
};

// Global Variable 
stUser CurrentUser;

// Functions definitions
void ShowMainMenu();
void ShowManageUsersMenu();
void ShowTransactionsMenu();
void GoBackToMainMenu();
void Login();


// General Functions
string Tabs(short NumberOfTabs)
{
	string Tabs;
	for (short i = 0; i < NumberOfTabs; i++)
	{
		Tabs += "\t";
	}
	return Tabs;
}
vector<string>SplitString(string S, string Delim)
{
	vector<string>VString;
	string Sword;
	short Pos = 0;

	while ((Pos = S.find(Delim)) != string::npos)
	{
		Sword = S.substr(0, Pos);

		if (!Sword.empty())
		{
			VString.push_back(Sword);
		}
		S.erase(0, Pos + Delim.length());
	}
	if (!S.empty())
	{
		VString.push_back(S);
	}
	return VString;
}
void DeniedAccessMessage()
{
	
	cout << "\nDenied Access! You can't do that Please contact you Admin...";
}

// Reading Functions
string ReadAccountNumber()
{
	string AccountNumber;
	cout << "\nEnter Account Number? "; getline(cin >> ws, AccountNumber);
	return AccountNumber;
}
string ReadUsername()
{
	string Username;
	cout << "\nEnter Username? "; cin >> Username;
	return Username;
}
string ReadPassword()
{
	string Password;
	cout << "\nEnter Password? "; cin >> Password;
	return Password;
}
int ReadPermissionsToSet()
{
	int Permissios = 0;
	char ans = 'y';

	cout << "\nDo you want full access?Y/N? "; cin >> ans;
	if (toupper(ans) == 'Y')
	{
		return -1;
	}

	cout << "\nDo you want access to : \n";
	
	cout << "Show Client List?Y/N? "; cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PClientList;
	}

	cout << "Add New ClientY/N? "; cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PAddNewClient;
	}

	cout << "Delete Client?Y/N? "; cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PDeleteClient;
	}

	cout << "Update Client?Y/N? "; cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PUpdateClient;
	}

	cout << "Find Client?Y/N? "; cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PFindClient;
	}

	cout << "Transactions?Y/N? "; cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PTransactions;
	}

	cout << "Manage Users?Y/N? "; cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PMangeUsers;
	}

	return Permissios;
}
bool HasPermissions(enPermissions Permissions)
{
	if (CurrentUser.Permissions == PAll)
		return true;

	if ((CurrentUser.Permissions & Permissions) == Permissions)
		return true;
	else
		return false;
}

//***********************************[Clients Functions]*******************************************

// Load From File

stClient ConvertClientLineToRecord(string S, string Delim = "#//#")
{
	vector<string>VString = SplitString(S, Delim);

	stClient Client;

	Client.AccountNumber = VString[0];
	Client.PinCode = VString[1];
	Client.Name = VString[2];
	Client.Phone = VString[3];
	Client.AccountBalance = stod(VString[4]);
	return Client;
}
vector<stClient>LoadClientDataFromFile(string FileName)
{
	vector<stClient>VClient;
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line; stClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertClientLineToRecord(Line);
			VClient.push_back(Client);
		}
		MyFile.close();
	}
	return VClient;
}

// Save To File Functions
string ConvertClientRecordToLine(stClient Client, string Delim = "#//#")
{
	string RecordLine;

	RecordLine += Client.AccountNumber + Delim;
	RecordLine += Client.PinCode + Delim;
	RecordLine += Client.Name + Delim;
	RecordLine += Client.Phone + Delim;
	RecordLine += to_string(Client.AccountBalance);
	return RecordLine;
}
vector<stClient>SaveClientDataToFile(string FileName, vector<stClient>VClient)
{
	fstream MyFile;
	string SDateLine;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (stClient C : VClient)
		{
			SDateLine = ConvertClientRecordToLine(C);

			if (C.MarkToDeleteClient == false)
			{

				MyFile << SDateLine << endl;
			}
		}
		MyFile.close();
	}
	return VClient;
}
// Client List and Card

void PrintClientCard(stClient Client)
{
	cout << "\nThe Following are the Client Details";
	cout << "\n-------------------------------------------";
	cout << "\nAccount Number  :" << Client.AccountNumber;
	cout << "\nPin Code        :" << Client.PinCode;
	cout << "\nClient Name     :" << Client.Name;
	cout << "\nClient Phone    :" << Client.Phone;
	cout << "\nAccount Balance :" << Client.AccountBalance;
	cout << "\n-------------------------------------------\n";
}
void PrintClientRecord(stClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.AccountBalance << " |";
}
void ShowClientsList()
{
	if (!HasPermissions(PClientList))
	{
		DeniedAccessMessage();
		GoBackToMainMenu();
		return; 
	}

	vector<stClient>VClient = LoadClientDataFromFile(ClientsFile);
	cout << "-----------------------------------------------------------";
	cout << "------------------------------------------" << endl;
	cout << Tabs(4) << "Clients List (" << VClient.size() << ") Client/s.\n";
	cout << "\n-----------------------------------------------------------";
	cout << "------------------------------------------" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "PinCode";
	cout << "| " << left << setw(40) << "Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance" << " |";
	cout << "\n-----------------------------------------------------------";
	cout << "------------------------------------------" << endl;
	if (VClient.size() == 0)
		cout << Tabs(3) << "No Clients Available in the system.";
	else
		for (stClient C : VClient)
		{
			PrintClientRecord(C);
			cout << endl;
		}
	cout << "-----------------------------------------------------------";
	cout << "------------------------------------------" << endl;
}
// Show Total Balances List

void PrintTotalBalancesRecord(stClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}
void ShowTotalBalancesList()
{

	vector<stClient>VClient = LoadClientDataFromFile(ClientsFile);
	cout << "--------------------------------------------------";
	cout << "------------------------------------------" << endl;
	cout << Tabs(3) << "Clients List (" << VClient.size() << ") Client/s.\n";
	cout << "--------------------------------------------------";
	cout << "------------------------------------------" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Name";
	cout << "| " << left << setw(12) << "Account Balance";
	cout << "\n--------------------------------------------------";
	cout << "------------------------------------------" << endl;
	double Balances = 0;
	if (VClient.size() == 0)
		cout << Tabs(3) << "No Clients Available in the system.";
	else
		for (stClient C : VClient)
		{
			PrintTotalBalancesRecord(C);
			Balances += C.AccountBalance;
			cout << endl;
		}
	cout << "--------------------------------------------------";
	cout << "------------------------------------------" << endl;
	cout << Tabs(3) << "Total Balances : " << Balances << endl;
}

// Add New Client Functions

bool IsClientExist(string AccountNumber, string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line; stClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertClientLineToRecord(Line);

			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
	}
	return false;
}
stClient ReadClientData()
{
	stClient Client;
	cout << "Enter Account Number? "; getline(cin >> ws, Client.AccountNumber);
	while(IsClientExist(Client.AccountNumber,ClientsFile))
	{ 
		cout << "\nAccount Number [" << Client.AccountNumber << "] is already exist\n";
		cout << "Enter Account Number? "; getline(cin >> ws, Client.AccountNumber);
	}
	cout << "Enter Pin Code? "; getline(cin, Client.PinCode);
	cout << "Enter Client Name? "; getline(cin, Client.Name);
	cout << "Enter Client Phone? "; getline(cin, Client.Phone);
	cout << "Enter Account Balance? "; cin >> Client.AccountBalance;
	return Client;
}
void SaveClientRecordToFile(string FileName, string SDataLine)
{
	fstream MyFile;
	 
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << SDataLine << endl;
		MyFile.close();
	}
}
void AddNewClient()
{
	stClient Client = ReadClientData();

	SaveClientRecordToFile(ClientsFile, ConvertClientRecordToLine(Client));
}
void AddMoreClients()
{
	char ans = 'n';
	do
	{
		system("cls");
		cout << "\nAdd New Client : \n";
		AddNewClient();
		cout << "\nDo you want add new client?Y/N? "; cin >> ans;
	} while (toupper(ans) == 'Y');
}
void ShowAddClientScreen()
{
	if (!HasPermissions(PAddNewClient))
	{
		DeniedAccessMessage();
		GoBackToMainMenu();
		return;
	}

	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Add New Client.\n";
	cout << "----------------------------------------------\n";
	AddMoreClients();
}

// Find And Mark To Delete Client

bool FindClientByAccountNumber(string AccountNumber, vector<stClient>& VClient, stClient& Client)
{
	for (stClient& C : VClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}
bool MarkToDeleteClient(string AccountNumber, vector<stClient>& VClient)
{
	for (stClient& C : VClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkToDeleteClient = true;
			return true;
		}
	}
	return false;
}
// Delete Update Find Deposit and withdraw functions
bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& VClient)
{
	char ans = 'y';
	stClient Client;
	if (FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		PrintClientCard(Client);
		cout << "\nAre you sure you want delete this client?Y/N"; cin >> ans;
		if (toupper(ans) == 'Y')
		{
			MarkToDeleteClient(AccountNumber, VClient);
			SaveClientDataToFile(ClientsFile, VClient);
			VClient = LoadClientDataFromFile(ClientsFile);
			cout << "\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nAccount Number [" << AccountNumber << "] is not found!";
		return false;
	}
}
stClient ChangeClientData(string AccountNumber)
{
	stClient Client;
	Client.AccountNumber = AccountNumber;
	cout << "Enter Pin Code? "; getline(cin >> ws, Client.PinCode);
	cout << "Enter Client Name? "; getline(cin, Client.Name);
	cout << "Enter Client Phone? "; getline(cin, Client.Phone);
	cout << "Enter Account Balance? "; cin >> Client.AccountBalance;
	return Client;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& VClient)
{
	char ans = 'n';
	stClient Client;
	if (FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		PrintClientCard(Client);
		cout << "\nAre you sure you want Update this client?Y/N?"; cin >> ans;
		if (toupper(ans) == 'Y')
		{
			for (stClient& C : VClient)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientData(AccountNumber);
					break;
					
				}
				
			}
			SaveClientDataToFile(ClientsFile, VClient);
			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nAccount Number [" << AccountNumber << "] is not found!";
		return false;
	}
}
bool DepositByAccountNumber(string AccountNumber, double Amount, vector<stClient>& VClient)
{
	char ans = 'n';

	cout << "\nAre you sure you want do this proccess?Y/N? "; cin >> ans;
	if (toupper(ans) == 'Y')
	{
		for (stClient& C : VClient)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientDataToFile(ClientsFile, VClient);
				cout << "\nSuccessFull Proccess New Balance is : " << C.AccountBalance << endl;
				return true;
			}
		}
	}
	return false;
}
// All Show Functions

void ShowDeleteClient()
{
	if (!HasPermissions(PDeleteClient))
	{
		DeniedAccessMessage();
		GoBackToMainMenu();
		return;
	}

	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Delete Client.\n";
	cout << "----------------------------------------------\n";
	string AccountNumber = ReadAccountNumber();
	vector<stClient>VClient = LoadClientDataFromFile(ClientsFile);

	DeleteClientByAccountNumber(AccountNumber, VClient);
}
void ShowUpdateClient()
{
	if (!HasPermissions(PUpdateClient))
	{
		DeniedAccessMessage();
		GoBackToMainMenu();
		return;
	}

	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Update Client.\n";
	cout << "----------------------------------------------\n";
	string AccountNumber = ReadAccountNumber();
	vector<stClient>VClient = LoadClientDataFromFile(ClientsFile);

	UpdateClientByAccountNumber(AccountNumber, VClient);
}
void ShowFindClient()
{
	if (!HasPermissions(PFindClient))
	{
		DeniedAccessMessage();
		GoBackToMainMenu();
		return;
	}

	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Find Client.\n";
	cout << "----------------------------------------------\n";
	string AccountNumber = ReadAccountNumber();
	vector<stClient>VClient = LoadClientDataFromFile(ClientsFile);
	stClient Client;

	if (FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nAccount Number [" << AccountNumber << "] is not found!";
	}
}
void ShowDpositScreen()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Deposit Screen.\n";
	cout << "----------------------------------------------\n";
	string AccountNumber = ReadAccountNumber();
	vector<stClient>VClient = LoadClientDataFromFile(ClientsFile);
	stClient Client;
	while (!FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		system("cls");
		cout << "----------------------------------------------\n";
		cout << Tabs(3) << "Deposit Screen.\n";
		cout << "----------------------------------------------\n";
		cout << "\nAccount Number [" << AccountNumber << "] does not exist\n";
		cout << "Enter Another Account Number? "; cin >> AccountNumber;
	}
	PrintClientCard(Client);
	double Amount;
	cout << "\nEnter Amount You want Deposit : "; cin >> Amount;

	DepositByAccountNumber(AccountNumber, Amount, VClient);
}
void ShowWithdrawScreen()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Withdraw Screen.\n";
	cout << "----------------------------------------------\n";
	string AccountNumber = ReadAccountNumber();
	vector<stClient>VClient = LoadClientDataFromFile(ClientsFile);
	stClient Client;
	while (!FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		system("cls");
		cout << "----------------------------------------------\n";
		cout << Tabs(3) << "Withdraw Screen.\n";
		cout << "----------------------------------------------\n";
		cout << "\nAccount Number [" << AccountNumber << "] does not exist\n";
		cout << "Enter Another Account Number? "; cin >> AccountNumber;
	}
	PrintClientCard(Client);
	double Amount;
	cout << "\nEnter Amount You want Withdraw : "; cin >> Amount;
	while (Amount > Client.AccountBalance)
	{
		cout << "\n\nAmount Exceeds Balance You can Withdraw Up to : " << Client.AccountBalance;
		cout << "\n\nEnter Another Amount : "; cin >> Amount;
	}

	DepositByAccountNumber(AccountNumber, -1 * Amount, VClient);
}

//************************************************[Users Functions]****************************************************
//Load to file 
stUser ConvertUserLineToRecord(string S, string Delim = "#//#")
{
	vector<string>VString = SplitString(S, Delim);

	stUser User;

	User.Username = VString[0];
	User.Password = VString[1];
	User.Permissions = stoi(VString[2]);
	return User;
}
vector<stUser>LoadUserDataFromFile(string FileName)
{
	vector<stUser>VUser;
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line; stUser User;
		while (getline(MyFile, Line))
		{
			User = ConvertUserLineToRecord(Line);
			VUser.push_back(User);
		}
		MyFile.close();
	}
	return VUser;
}

// Save To File Functions
string ConvertUserRecordToLine(stUser User, string Delim = "#//#")
{
	string RecordLine;

	RecordLine += User.Username + Delim;
	RecordLine += User.Password + Delim;
	RecordLine += to_string(User.Permissions);
	return RecordLine;
}
vector<stUser>SaveUserDataToFile(string FileName, vector<stUser>VUser)
{
	fstream MyFile;
	string SDateLine;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (stUser U : VUser)
		{
			SDateLine = ConvertUserRecordToLine(U);

			if (U.MarkToDeleteUser == false)
			{
				MyFile << SDateLine << endl;
			}
		}
		MyFile.close();
	}
	return VUser;
}
// Users List and Card

void PrintUserCard(stUser User)
{
	cout << "\nThe Following are the User Details";
	cout << "\n-------------------------------------------";
	cout << "\nUsername    :" << User.Username;
	cout << "\nPassword    :" << User.Password;
	cout << "\nPermissions :" << User.Permissions;
	cout << "\n-------------------------------------------\n";
}
void PrintUsersRecord(stUser User)
{
	cout << "| " << left << setw(15) << User.Username;
	cout << "| " << left << setw(15) << User.Password;
	cout << "| " << left << setw(12) << User.Permissions;
}
void ShowUsersList()
{

	vector<stUser>VUser = LoadUserDataFromFile(UsersFile);
	cout << "--------------------------------------------------";
	cout << "------------------------------------------" << endl;
	cout << Tabs(3) << "Users List (" << VUser.size() << ") User/s.\n";
	cout << "--------------------------------------------------";
	cout << "------------------------------------------" << endl;
	cout << "| " << left << setw(15) << "username";
	cout << "| " << left << setw(15) << "Password";
	cout << "| " << left << setw(12) << "Permissions";
	cout << "\n--------------------------------------------------";
	cout << "------------------------------------------" << endl;
	if (VUser.size() == 0)
		cout << Tabs(3) << "No Users Available in the system.";
	else
		for (stUser U : VUser)
		{
			PrintUsersRecord(U);
			cout << endl;
		}
	cout << "--------------------------------------------------";
	cout << "------------------------------------------" << endl;
}

// Add New User Functions

bool IsUserExist(string UserName, string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line; stUser User;
		while (getline(MyFile, Line))
		{
			User = ConvertUserLineToRecord(Line);

			if (User.Username == UserName)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
	}
	return false;
}
stUser ReadUserData()
{
	stUser User;
	cout << "Enter UserName? "; getline(cin >> ws, User.Username);
	while (IsUserExist(User.Username, UsersFile))
	{
		cout << "\nUsername [" << User.Username << "] is already exist\n";
		cout << "Enter Another Username? "; getline(cin >> ws, User.Username);
	}
	cout << "Enter Password? "; getline(cin, User.Password);
	User.Permissions = ReadPermissionsToSet();
	return User;
}
void SaveUserRecordToFile(string FileName, string SDataLine)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << SDataLine << endl;
		MyFile.close();
	}
}
void AddNewUser()
{
	stUser User = ReadUserData();

	SaveUserRecordToFile(UsersFile, ConvertUserRecordToLine(User));
}
void AddMoreUsers()
{
	char ans = 'n';
	do
	{
		system("cls");
		cout << "\nAdd New User : \n";
		AddNewUser();
		cout << "\nDo you want add new User?Y/N? "; cin >> ans;
	} while (toupper(ans) == 'Y');
}
void ShowAddUserScreen()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Add New Client.\n";
	cout << "----------------------------------------------\n";
	
	AddMoreUsers();
}

// Find And Mark To Delete User
bool FindUserByUsernameAndPassword(string Username, string Password,vector<stUser>& VUser, stUser& User)
{
	for (stUser& U : VUser)
	{
		if (U.Username == Username && U.Password == Password)
		{
			User = U;
			return true;
		}
	}
	return false;
}
bool IsLoginSuccessful(string Username, string Password)
{
	vector<stUser>VUser = LoadUserDataFromFile(UsersFile);
	return (FindUserByUsernameAndPassword(Username, Password, VUser, CurrentUser));
}

bool FindUserByUsername(string Username, vector<stUser>& VUser, stUser& User)
{
	for (stUser& U : VUser)
	{
		if (U.Username == Username)
		{
			User = U;
			return true;
		}
	}
	return false;
}
bool MarkToDeleteUser(string Username, vector<stUser>& VUser)
{
	for (stUser& U : VUser)
	{
		if (U.Username == Username)
		{
			U.MarkToDeleteUser = true;
			return true;
		}
	}
	return false;
}
// Delete Update Find Deposit and withdraw functions
bool DeleteUserByUsername(string Username, vector<stUser>& VUser)
{
	char ans = 'y';
	stUser User;
	if (FindUserByUsername(Username, VUser, User))
	{
		PrintUserCard(User);
		cout << "\nAre you sure you want delete this User?Y/N"; cin >> ans;
		if (toupper(ans) == 'Y')
		{
			MarkToDeleteUser(Username, VUser);
			SaveUserDataToFile(UsersFile, VUser);
			VUser = LoadUserDataFromFile(UsersFile);
			cout << "\nUser Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nUsername [" << Username << "] is not found!";
		return false;
	}
}
stUser ChangeUserData(string Username)
{
	stUser User;
	User.Username = Username;
	cout << "Enter Password? "; getline(cin >> ws, User.Password);
	User.Permissions = ReadPermissionsToSet();
	return User;
}
bool UpdateUserByUsername(string Username, vector<stUser>& VUser)
{
	char ans = 'n';
	stUser User;
	if (FindUserByUsername(Username, VUser, User))
	{
		PrintUserCard(User);
		cout << "\nAre you sure you want Update this User?Y/n"; cin >> ans;
		if (toupper(ans) == 'Y')
		{
			for (stUser U : VUser)
			{
				if (U.Username == Username)
				{
					U = ChangeUserData(Username);
					break;
				}
				
			}
			SaveUserDataToFile(UsersFile, VUser);
			cout << "\nUser Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nUsername [" << Username << "] is not found!";
		return false;
	}
}
// All Show Functions

void ShowDeleteUser()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Delete User.\n";
	cout << "----------------------------------------------\n";
	string Username = ReadUsername();
	vector<stUser>VUser = LoadUserDataFromFile(UsersFile);

	DeleteUserByUsername(Username, VUser);
}
void ShowUpdateUser()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Update User.\n";
	cout << "----------------------------------------------\n";
	string Username = ReadUsername();
	vector<stUser>VUser = LoadUserDataFromFile(UsersFile);

	UpdateUserByUsername(Username, VUser);
}
void ShowFindUser()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Find User.\n";
	cout << "----------------------------------------------\n";
	string Username = ReadUsername();
	vector<stUser>VUser = LoadUserDataFromFile(UsersFile);
	stUser User;

	if (FindUserByUsername(Username, VUser, User))
	{
		PrintUserCard(User);
	}
	else
	{
		cout << "\nUsername [" << Username << "] is not found!";
	}
}

//*************************************************************************************************************************

//Menus
// Transactions
short ChoseFromTransactionsMenu()
{
	short Choice;
	cout << "\nChose What do you want to do from [1] to [4] ? "; cin >> Choice;
	return Choice;
}
void GoBackToTransactionsMenu()
{
	cout << "\nPress Any Key To Go Back To Transactions Menu....."; system("pause>0");
	ShowTransactionsMenu();
}
void PerformTransactionsMenuOptions(enTransactionsMenu Trans)
{
	switch (Trans)
	{
	case Deposit:
		system("cls");
		ShowDpositScreen();
		GoBackToTransactionsMenu();
		break;

	case Withdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenu();
		break;

	case TotalBalances:
		system("cls");
		ShowTotalBalancesList();
		GoBackToTransactionsMenu();
		break;

	case ReturnToMainMenu:
		ShowMainMenu();
		break;
	}
}
void ShowTransactionsMenu()
{
	if (!HasPermissions(PTransactions))
	{
		DeniedAccessMessage();
		GoBackToMainMenu();
		return;
	}

	system("cls");
	cout << "======================================================\n";
	cout << Tabs(3) << "Transactions Menu Screen.\n";
	cout << "======================================================\n";
	cout << Tabs(2) << "[1] Deposit.\n";
	cout << Tabs(2) << "[2] Withdraw.\n";
	cout << Tabs(2) << "[3] Total Balances.\n";
	cout << Tabs(2) << "[4] Return To Main Menu.\n";
	cout << "======================================================\n";
	PerformTransactionsMenuOptions((enTransactionsMenu)ChoseFromTransactionsMenu());
}
// Manage Users Menu
short ChoseFromManageUsersMenu()
{
	short Choice;
	cout << "\nChose What do you want to do from [1] to [6] ? "; cin >> Choice;
	return Choice;
}
void GoBackToManageUsersMenu()
{
	cout << "\nPress Any Key To Go Back To Manage Users Menu....."; system("pause>0");
	ShowManageUsersMenu();
}
void PerformManageUsersMenuOptions(enManageUserMenu Manage)
{
	switch (Manage)
	{
	case UsersList:
		system("cls");
		ShowUsersList();
		GoBackToManageUsersMenu();
		break;

	case AddUser:
		system("cls");
		ShowAddUserScreen();
		GoBackToManageUsersMenu();
		break;

	case DeleteUser:
		system("cls");
		ShowDeleteUser();
		GoBackToManageUsersMenu();
		break;

	case UpdateUser:
		system("cls");
		ShowUpdateUser();
		GoBackToManageUsersMenu();
		break;

	case FindUser:
		system("cls");
		ShowFindUser();
		GoBackToManageUsersMenu();
		break;

	case MainMenu:
		ShowMainMenu();
		break;
	}
}
void ShowManageUsersMenu()
{
	if (!HasPermissions(PMangeUsers))
	{
		DeniedAccessMessage();
		GoBackToMainMenu();
		return;
	}

	system("cls");
	cout << "======================================================\n";
	cout << Tabs(3) << "Manage User Menu Screen.\n";
	cout << "======================================================\n";
	cout << Tabs(2) << "[1] Show Users List.\n";
	cout << Tabs(2) << "[2] Add New User.\n";
	cout << Tabs(2) << "[3] Delete User.\n";
	cout << Tabs(2) << "[4] Update User.\n";
	cout << Tabs(2) << "[5] Find User.\n";
	cout << Tabs(2) << "[6] Return To Main Menu.\n";
	cout << "======================================================\n";
	PerformManageUsersMenuOptions((enManageUserMenu)ChoseFromManageUsersMenu());
}
//Main Menu
short ChoseFromMainMenu()
{
	short Choice;
	cout << "\nChose What do you want to do from [1] to [8] ? "; cin >> Choice;
	return Choice;
}
void GoBackToMainMenu()
{
	cout << "\nPress Any Key To Go Back To Main Menu....."; system("pause>0");
	ShowMainMenu();
}
void PerformMainMenuOptions(enMainMenuOptions Menu)
{
	switch (Menu)
	{
	case eClientsList:
		system("cls");
		ShowClientsList();
		GoBackToMainMenu();
		break;

	case eAddNewClient:
		system("cls");
		ShowAddClientScreen();
		GoBackToMainMenu();
		break;

	case eDeleteClient:
		system("cls");
		ShowDeleteClient();
		GoBackToMainMenu();
		break;

	case eUpdateClient:
		system("cls");
		ShowUpdateClient();
		GoBackToMainMenu();
		break;

	case eFindClient:
		system("cls");
		ShowFindClient();
		GoBackToMainMenu();
		break;

	case eTransactions:
		system("cls");
		ShowTransactionsMenu();
		break;

	case eMangeUser:
		system("cls");
		ShowManageUsersMenu();
		break;

	case eLogout:
		Login();
		break;
	}
}
void ShowMainMenu()
{
	system("cls");
	cout << "======================================================\n";
	cout << Tabs(3) << "Main Menu Screen.\n";
	cout << "======================================================\n";
	cout << Tabs(2) << "[1] Show Clients List.\n";
	cout << Tabs(2) << "[2] Add New Client.\n";
	cout << Tabs(2) << "[3] Delete Client.\n";
	cout << Tabs(2) << "[4] Update Client.\n";
	cout << Tabs(2) << "[5] Find Client.\n";
	cout << Tabs(2) << "[6] Transactions.\n";
	cout << Tabs(2) << "[7] Manage Users INFO.\n";
	cout << Tabs(2) << "[8] Logout.\n";
	cout << "======================================================\n";
	PerformMainMenuOptions((enMainMenuOptions)ChoseFromMainMenu());
}
void Login()
{
	string Username, Password;

	bool LoginFail = false;
	do
	{
		system("cls");
		cout << "----------------------------------------------\n";
		cout << Tabs(3) << "Login Screen.\n";
		cout << "----------------------------------------------\n";

		if (LoginFail)
		{
			
			cout << "\nInvalid Username/Password!\n";
		}
		Username = ReadUsername();
		Password = ReadPassword();
		LoginFail = !IsLoginSuccessful(Username, Password);

	} while (LoginFail);

	ShowMainMenu();
}
int main()
{
	Login();
	system("pause>0");
	return 0;
}










  

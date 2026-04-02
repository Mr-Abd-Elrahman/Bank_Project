
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
enum enMainMenuOptions
{
	eClientsList = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClient = 4,
	eFindClient = 5,
	eTransactions = 6,
	eMangeUser = 7,
	eLogout = 8
};

enum enTransactionsMenu
{
	Deposit = 1,
	Withdraw = 2,
	TotalBalances = 3,
	ReturnToMainMenu = 4
};

enum enManageUserMenu
{
	UsersList = 1,
	AddUser = 2,
	DeleteUser = 3,
	UpdateUser = 4,
	FindUser = 5,
	MainMenu
};

enum enPermissions
{
	PAll = -1,
	PClientList = 1,
	PAddNewClient = 2,
	PDeleteClient = 4,
	PUpdateClient = 8,
	PFindClient = 16,
	PTransactions = 32,
	PMangeUsers = 64
};

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
vector<string> SplitString(string S, string Delim)
{
	vector<string> VString;
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
	cout << "\nEnter Account Number? ";
	getline(cin >> ws, AccountNumber);
	return AccountNumber;
}
string ReadUsername()
{
	string Username;
	cout << "\nEnter Username? ";
	cin >> Username;
	return Username;
}
string ReadPassword()
{
	string Password;
	cout << "\nEnter Password? ";
	cin >> Password;
	return Password;
}
int ReadPermissionsToSet()
{
	int Permissios = 0;
	char ans = 'y';

	cout << "\nDo you want full access?Y/N? ";
	cin >> ans;
	if (toupper(ans) == 'Y')
	{
		return -1;
	}

	cout << "\nDo you want access to : \n";

	cout << "Show Client List?Y/N? ";
	cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PClientList;
	}

	cout << "Add New ClientY/N? ";
	cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PAddNewClient;
	}

	cout << "Delete Client?Y/N? ";
	cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PDeleteClient;
	}

	cout << "Update Client?Y/N? ";
	cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PUpdateClient;
	}

	cout << "Find Client?Y/N? ";
	cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PFindClient;
	}

	cout << "Transactions?Y/N? ";
	cin >> ans;

	if (toupper(ans) == 'Y')
	{
		Permissios += PTransactions;
	}

	cout << "Manage Users?Y/N? ";
	cin >> ans;

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
	vector<string> VString = SplitString(S, Delim);

	stClient Client;

	Client.AccountNumber = VString[0];
	Client.PinCode = VString[1];
	Client.Name = VString[2];
	Client.Phone = VString[3];
	Client.AccountBalance = stod(VString[4]);
	return Client;
}
vector<stClient> LoadClientDataFromFile(string FileName)
{
	vector<stClient> VClient;
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;
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
vector<stClient> SaveClientDataToFile(string FileName, vector<stClient> VClient)
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

	vector<stClient> VClient = LoadClientDataFromFile(ClientsFile);
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

	vector<stClient> VClient = LoadClientDataFromFile(ClientsFile);
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
		string Line;
		stClient Client;
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
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);
	while (IsClientExist(Client.AccountNumber, ClientsFile))
	{
		cout << "\nAccount Number [" << Client.AccountNumber << "] is already exist\n";
		cout << "Enter Account Number? ";
		getline(cin >> ws, Client.AccountNumber);
	}
	cout << "Enter Pin Code? ";
	getline(cin, Client.PinCode);
	cout << "Enter Client Name? ";
	getline(cin, Client.Name);
	cout << "Enter Client Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;
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
		system("clear");
		cout << "\nAdd New Client : \n";
		AddNewClient();
		cout << "\nDo you want add new client?Y/N? ";
		cin >> ans;
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

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> &VClient, stClient &Client)
{
	for (stClient &C : VClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}
bool MarkToDeleteClient(string AccountNumber, vector<stClient> &VClient)
{
	for (stClient &C : VClient)
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
bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient> &VClient)
{
	char ans = 'y';
	stClient Client;
	if (FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		PrintClientCard(Client);
		cout << "\nAre you sure you want delete this client?Y/N";
		cin >> ans;
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
	cout << "Enter Pin Code? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Client Name? ";
	getline(cin, Client.Name);
	cout << "Enter Client Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;
	return Client;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient> &VClient)
{
	char ans = 'n';
	stClient Client;
	if (FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		PrintClientCard(Client);
		cout << "\nAre you sure you want Update this client?Y/N?";
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			for (stClient &C : VClient)
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
bool DepositByAccountNumber(string AccountNumber, double Amount, vector<stClient> &VClient)
{
	char ans = 'n';

	cout << "\nAre you sure you want do this proccess?Y/N? ";
	cin >> ans;
	if (toupper(ans) == 'Y')
	{
		for (stClient &C : VClient)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientDataToFile(ClientsFile, VClient);
			}
			cout << "\nSuccessFull Proccess New Balance is : " << C.AccountBalance << endl;
			return true;
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
	vector<stClient> VClient = LoadClientDataFromFile(ClientsFile);

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
	vector<stClient> VClient = LoadClientDataFromFile(ClientsFile);

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
	vector<stClient> VClient = LoadClientDataFromFile(ClientsFile);
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
	vector<stClient> VClient = LoadClientDataFromFile(ClientsFile);
	stClient Client;
	while (!FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		system("clear");
		cout << "----------------------------------------------\n";
		cout << Tabs(3) << "Deposit Screen.\n";
		cout << "----------------------------------------------\n";
		cout << "\nAccount Number [" << AccountNumber << "] does not exist\n";
		cout << "Enter Another Account Number? ";
		cin >> AccountNumber;
	}
	PrintClientCard(Client);
	double Amount;
	cout << "\nEnter Amount You want Deposit : ";
	cin >> Amount;

	DepositByAccountNumber(AccountNumber, Amount, VClient);
}
void ShowWithdrawScreen()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Withdraw Screen.\n";
	cout << "----------------------------------------------\n";
	string AccountNumber = ReadAccountNumber();
	vector<stClient> VClient = LoadClientDataFromFile(ClientsFile);
	stClient Client;
	while (!FindClientByAccountNumber(AccountNumber, VClient, Client))
	{
		system("cls");
		cout << "----------------------------------------------\n";
		cout << Tabs(3) << "Withdraw Screen.\n";
		cout << "----------------------------------------------\n";
		cout << "\nAccount Number [" << AccountNumber << "] does not exist\n";
		cout << "Enter Another Account Number? ";
		cin >> AccountNumber;
	}
	PrintClientCard(Client);
	double Amount;
	cout << "\nEnter Amount You want Withdraw : ";
	cin >> Amount;
	while (Amount > Client.AccountBalance)
	{
		cout << "\n\nAmount Exceeds Balance You can Withdraw Up to : " << Client.AccountBalance;
		cout << "\n\nEnter Another Amount : ";
		cin >> Amount;
	}

	DepositByAccountNumber(AccountNumber, -1 * Amount, VClient);
}

//************************************************[Users Functions]****************************************************
// Load to file
stUser ConvertUserLineToRecord(string S, string Delim = "#//#")
{
	vector<string> VString = SplitString(S, Delim);

	stUser User;

	User.Username = VString[0];
	User.Password = VString[1];
	User.Permissions = stoi(VString[2]);
	return User;
}
vector<stUser> LoadUserDataFromFile(string FileName)
{
	vector<stUser> VUser;
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stUser User;
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
vector<stUser> SaveUserDataToFile(string FileName, vector<stUser> VUser)
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

	vector<stUser> VUser = LoadUserDataFromFile(UsersFile);
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
		string Line;
		stUser User;
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
	cout << "Enter UserName? ";
	getline(cin >> ws, User.Username);
	while (IsUserExist(User.Username, UsersFile))
	{
		cout << "\nUsername [" << User.Username << "] is already exist\n";
		cout << "Enter Another Username? ";
		getline(cin >> ws, User.Username);
	}
	cout << "Enter Password? ";
	getline(cin, User.Password);
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
		system("clear");
		cout << "\nAdd New User : \n";
		AddNewUser();
		cout << "\nDo you want add new User?Y/N? ";
		cin >> ans;
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
bool FindUserByUsernameAndPassword(string Username, string Password, vector<stUser> &VUser, stUser &User)
{
	for (stUser &U : VUser)
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
	vector<stUser> VUser = LoadUserDataFromFile(UsersFile);
	return (FindUserByUsernameAndPassword(Username, Password, VUser, CurrentUser));
}

bool FindUserByUsername(string Username, vector<stUser> &VUser, stUser &User)
{
	for (stUser &U : VUser)
	{
		if (U.Username == Username)
		{
			User = U;
			return true;
		}
	}
	return false;
}
bool MarkToDeleteUser(string Username, vector<stUser> &VUser)
{
	for (stUser &U : VUser)
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
bool DeleteUserByUsername(string Username, vector<stUser> &VUser)
{
	char ans = 'y';
	stUser User;
	if (FindUserByUsername(Username, VUser, User))
	{
		PrintUserCard(User);
		cout << "\nAre you sure you want delete this User?Y/N";
		cin >> ans;
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
	cout << "Enter Password? ";
	getline(cin >> ws, User.Password);
	User.Permissions = ReadPermissionsToSet();
	return User;
}
bool UpdateUserByUsername(string Username, vector<stUser> &VUser)
{
	char ans = 'n';
	stUser User;
	if (FindUserByUsername(Username, VUser, User))
	{
		PrintUserCard(User);
		cout << "\nAre you sure you want Update this User?Y/n";
		cin >> ans;
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
	vector<stUser> VUser = LoadUserDataFromFile(UsersFile);

	DeleteUserByUsername(Username, VUser);
}
void ShowUpdateUser()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Update User.\n";
	cout << "----------------------------------------------\n";
	string Username = ReadUsername();
	vector<stUser> VUser = LoadUserDataFromFile(UsersFile);

	UpdateUserByUsername(Username, VUser);
}
void ShowFindUser()
{
	cout << "----------------------------------------------\n";
	cout << Tabs(3) << "Find User.\n";
	cout << "----------------------------------------------\n";
	string Username = ReadUsername();
	vector<stUser> VUser = LoadUserDataFromFile(UsersFile);
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

// Menus
//  Transactions
short ChoseFromTransactionsMenu()
{
	short Choice;
	cout << "\nChose What do you want to do from [1] to [4] ? ";
	cin >> Choice;
	return Choice;
}
void GoBackToTransactionsMenu()
{
	cout << "\nPress Any Key To Go Back To Transactions Menu.....";
	cin.get();
	cin.get();
	ShowTransactionsMenu();
}
void PerformTransactionsMenuOptions(enTransactionsMenu Trans)
{
	switch (Trans)
	{
	case Deposit:
		system("clear");
		ShowDpositScreen();
		GoBackToTransactionsMenu();
		break;

	case Withdraw:
		system("clear");
		ShowWithdrawScreen();
		GoBackToTransactionsMenu();
		break;

	case TotalBalances:
		system("clear");
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

	system("clear");
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
	cout << "\nChose What do you want to do from [1] to [6] ? ";
	cin >> Choice;
	return Choice;
}
void GoBackToManageUsersMenu()
{
	cout << "\nPress Any Key To Go Back To Manage Users Menu.....";
	cin.get();
	cin.get();
	ShowManageUsersMenu();
}
void PerformManageUsersMenuOptions(enManageUserMenu Manage)
{
	switch (Manage)
	{
	case UsersList:
		system("clear");
		ShowUsersList();
		GoBackToManageUsersMenu();
		break;

	case AddUser:
		system("clear");
		ShowAddUserScreen();
		GoBackToManageUsersMenu();
		break;

	case DeleteUser:
		system("clear");
		ShowDeleteUser();
		GoBackToManageUsersMenu();
		break;

	case UpdateUser:
		system("clear");
		ShowUpdateUser();
		GoBackToManageUsersMenu();
		break;

	case FindUser:
		system("clear");
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

	system("clear");
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
// Main Menu
short ChoseFromMainMenu()
{
	short Choice;
	cout << "\nChose What do you want to do from [1] to [8] ? ";
	cin >> Choice;
	return Choice;
}
void GoBackToMainMenu()
{
	cout << "\nPress Any Key To Go Back To Main Menu.....";
	cin.get();
	cin.get();
	ShowMainMenu();
}
void PerformMainMenuOptions(enMainMenuOptions Menu)
{
	switch (Menu)
	{
	case eClientsList:
		system("clear");
		ShowClientsList();
		GoBackToMainMenu();
		break;

	case eAddNewClient:
		system("clear");
		ShowAddClientScreen();
		GoBackToMainMenu();
		break;

	case eDeleteClient:
		system("clear");
		ShowDeleteClient();
		GoBackToMainMenu();
		break;

	case eUpdateClient:
		system("clear");
		ShowUpdateClient();
		GoBackToMainMenu();
		break;

	case eFindClient:
		system("clear");
		ShowFindClient();
		GoBackToMainMenu();
		break;

	case eTransactions:
		system("clear");
		ShowTransactionsMenu();
		break;

	case eMangeUser:
		system("clear");
		ShowManageUsersMenu();
		break;

	case eLogout:
		Login();
		break;
	}
}
void ShowMainMenu()
{
	system("clear");
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
		system("clear");
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
	cin.get();
	return 0;
}

#define DPROG "rogerj"
void pruefjtab(DB *My, const string& touta, const int obverb, const int oblog, const uchar direkt=0);
class hhcl:public hcl
{
	private:
	public:
		uchar obvi=0; // ob Konfigurationsdatei editiert werden soll
		const string tjtab="jtab"; // MariaDB-Tabelle fuer Anrufjournal
    string dbq; // Datenbank
    string host="localhost";  // fuer MySQL/MariaDB
    string muser; // Benutzer fuer Mysql/MariaDB
    string mpwd;  // Passwort fuer Mysql/MariaDB
		const size_t maxconz=12;//aktc: 0=...
		uchar keineverarbeitung=0; // wenn cronminuten geaendert werden sollen, vorher abkuerzen
    DB* My=0;
		string csvs="/root/.local/share/routermanager/Schade/journal.csv";
	private:
		void lgnzuw();
	public:
		hhcl(const int argc, const char *const *const argv);
		~hhcl();
    void pruefggfmehrfach();
    int  initDB();
    int  pruefDB(const string& db);
		void pruefjtab(DB *My, const string& tjtab, const int obverb, const int oblog, const uchar direkt=0);
		void getcommandl0();
		void VorgbAllg();
		void VorgbSpeziell()
#ifdef VOMHAUPTCODE
			__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
			;
		void MusterVorgb();
		void lieskonfein();
		int getcommandline();
		void rueckfragen();
		void liescsv();
		void autokonfschreib();
		void zeigueberschrift();
}; // class hhcl

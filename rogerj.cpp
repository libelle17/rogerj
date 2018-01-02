#include "kons.h"
#include "DB.h"
#define VOMHAUPTCODE
#include "rogerj.h"

enum T_
{
 T_zu_schreiben,
 T_VorgbAllg,
 T_VorgbSpeziell,
 T_MusterVorgb,
 T_rueckfragen,
 T_autokonfschreib,
 T_pruefjtab,
 T_Anruftyp_1_ankommend_3_abgehend,
 T_Fehler_beim_Pruefen_von,
 T_Zeitpunkt_des_Verbindungsaufbaus,
 T_Name_des_Verbindungspartners,
 T_Rufnummer_des_Verbindungspartners,
 T_Nebenstelle_hier,
 T_Eigene_Rufnummer,
 T_Verbindungsdauer,
 T_Telefonprotokoll_der_Fritzbox,
 T_eindeutige_Identifikation,
 T_verwendet_die_Datenbank_auf_Host_string_anstatt_auf,
 T_verwendet_fuer_MySQL_MariaDB_den_Benutzer_string_anstatt,
 T_verwendet_fuer_MySQL_MariaDB_das_Passwort_string,
 T_verwendet_die_Datenbank_string_anstatt,
 T_Host_fuer_MySQL_MariaDB_Datenbank,
	T_Benutzer_fuer_MySQL_MariaDB,
	T_Passwort_fuer_MySQL_MariaDB,
	T_Datenbankname_fuer_MySQL_MariaDB_auf,
	Verbindung_zur_Datenbank_nicht_herstellbar,
	T_Breche_ab,
	T_pruefDB,
	T_host_k,
	T_host_l,
	T_muser_k,
	T_muser_l,
	T_mpwd_k,
	T_mpwd_l,
	T_db_k,
	T_datenbank_l,
	T_cm_k,
	T_cronminuten_l,
	T_nicht_erkannt,
	T_Liest_das_Fritzbox_Journal_Ueber_RogerRouter_aus_und_sammelt_es_in_einer_Datenbank,
	T_schreibe_Konfiguration,
	T_info_k,
	T_version_l,
	T_vi_k,
	T_vi_l,
	T_h_k,
	T_lh_k,
	T_hilfe_l,
	T_lhilfe_l,
	T_fgz_k,
	T_fgz_l,
	T_Zeigt_die_Programmversion_an,
	T_Konfigurations_u_Logdatei_bearbeiten_sehen,
	T_Erklaerung_haeufiger_Optionen,
	T_Erklaerung_aller_Optionen,
 T_MAX
}; // enum T_

char const *DPROG_T[T_MAX+1][SprachZahl]={
 // T_zu_schreiben
 {"zu schreiben: ","must write: "},
 // T_VorgbAllg
 {"VorgbAllg()","generalprefs()"},
 // T_VorgbSpeziell
 {"VorgbSpeziell()","specialprefs()"},
 // T_MusterVorgb
 {"MusterVorgb()","sampleprefs"},
 // T_rueckfragen
 {"rueckfragen()","callbacks()"},
 // T_autokonfschreib
 {"autokonfschreib()","autoconfwrite()"},
 // T_pruefjtab
 {"pruefjtab()","checkjtab()"},
 // T_Anruftyp_1_ankommend_3_abgehend
 {"Anruftyp: 1=ankommend, 3=abgehend","type of call: 1=incoming, 3=outgoing"},
 //	T_Fehler_beim_Pruefen_von
 {"Fehler beim Pruefen von: ","Error while examining: "},
 // T_Zeitpunkt_des_Verbindungsaufbaus
 {"Zeitpunkt des Verbindungsaufbaus","Start time of the connection"},
 // T_Name_des_Verbindungspartners
 {"Name des Verbindungspartners","Name of the Couterpart"},
 // T_Rufnummer_des_Verbindungspartners
 {"Rufnummer des Verbindungspartners","Dial number of the counterpart"},
 // T_Nebenstelle_hier
 {"Nebenstelle hier","party line here"},
 // T_Eigene_Rufnummer
 {"Eigene Rufnummer","Own calling number"},
 // T_Verbindungsdauer
 {"Verbindungsdauer","Connection duration"},
 // T_Telefonprotokoll_der_Fritzbox
 {"Telefonprotokoll der Fritzbox","Connection journal of the fritzbox"},
 // T_eindeutige_Identifikation
 {"eindeutige Identifiaktion","unique ID"},
 // T_verwendet_die_Datenbank_auf_Host_string_anstatt_auf
 {"verwendet die Datenbank auf Host <string> anstatt auf","takes the database on host <string> instead of"},
 // T_verwendet_fuer_MySQL_MariaDB_den_Benutzer_string_anstatt
 {"verwendet fuer MySQL/MariaDB den Benutzer <string> anstatt","takes the user <string> for MySQL/MariaDB instead of"},
 // T_verwendet_fuer_MySQL_MariaDB_das_Passwort_string
 {"verwendet fuer MySQL/MariaDB das Passwort <string>","takes the password <string> for MySQL/MariaDB"},
 // T_verwendet_die_Datenbank_string_anstatt
 {"verwendet die Datenbank <string> anstatt","uses the database <string> instead of"},
	// T_Host_fuer_MySQL_MariaDB_Datenbank
	{"Host fuer MySQL/MariaDB-Datenbank","host for mysql/mariadb-database"},
	// T_Benutzer_fuer_MySQL_MariaDB,
	{"Benutzer fuer MySQL/MariaDB:","user for mysql/mariadb:"},
	// T_Passwort_fuer_MySQL_MariaDB,
	{"Passwort fuer MySQL/MariaDB (Achtung: nur schwach verschluesselt!)","password for mysql/mariadb (caution: only weakly encrypted!)"},
	// T_Datenbankname_fuer_MySQL_MariaDB_auf
	{"Datenbankname fuer MySQL/MariaDB auf '","database name for mysql/mariabd on '"},
	// Verbindung_zur_Datenbank_nicht_herstellbar
	{"Verbindung zur Datenbank nicht herstellbar, fehnr: ","Connection to the database could not be established, errnr: "},
	// T_Breche_ab
	{". Breche ab.","Stopping."},
	// T_pruefDB
	{"pruefDB(","checkDB("},
	// T_host_k
	{"host","host"},
	// T_host_l
	{"host","host"},
	// T_muser_k
	{"muser","muser"},
	// T_muser_l
	{"muser","muser"},
	// T_mpwd_k
	{"mpwd","mpwd"},
	// T_mpwd_l
	{"mpwd","mpwd"},
	// T_db_k
	{"db","db"},
	// T_datenbank_l
	{"datenbank","database"},
	// T_cm_k
	{"cm","cm"},
	// T_cronminuten_l
	{"cronminuten","cronminutes"},
	// T_nicht_erkannt
	{" nicht erkannt!"," not identified!"},
	// T_Liest_das_Fritzbox_Journal_Ueber_RogerRouter_aus_und_sammelt_es_in_einer_Datenbank
	{"Liest das Fritzbox Journal über RogerRouter aus und sammelt es einer Datenbank",
		"Reads the fritzbox journal via roger router and collects in in a database"},
	// T_schreibe_Konfiguration
	{"schreibe Konfiguration!","writing configuration!"},
	// T_info_k
	{"info","info"},
	// T_version_l
	{"version","version"},
	// T_vi_k
	{"vi","vi"},
	// T_vi_l
	{"vi","vi"},
	// T_vc_k
	{"h","h"},
	// T_lh_k
	{"lh","lh"},
	// T_hilfe_l
	{"hilfe","help"},
	// T_lhilfe_l
	{"langhilfe","longhelp"},
	// T_fgz_k
	{"?","?"},
	// T_fgz_l,
	{"??","??"},
	// T_Zeigt_die_Programmversion_an
	{"Zeigt die Programmversion an","shows the program version"},
	// T_Konfigurations_u_Logdatei_bearbeiten_sehen
	{"Konfigurations- u.Logdatei bearbeiten/sehen (beenden mit ':qa')","edit/view configuration and log file (finish with ':qa')"},
	// 	T_Erklaerung_haeufiger_Optionen
	{"Erklärung häufiger Optionen","Explanation of frequent options"},
	// T_Erklaerung_aller_Optionen
	{"Erklärung aller Optionen","Explanation of all options"},
	{"",""}
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);

uchar ZDB=0; // fuer Zusatz-Debugging (SQL): ZDB 1, sonst: 0
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen; muss dann auf lgp zeigen;
const string& pwk = "8m49023ß8A490qdmjsaop4a89d0qÃ9m0943Ã09Ãax"; // fuer Antlitzaenderung

using namespace std;
#ifdef mitpostgres 
const DBSTyp myDBS=Postgres;
#else // mitpostgre
const DBSTyp myDBS=MySQL;
#endif // mitpostgres else

// wird aufgerufen in: main
void pruefjtab(DB *My, const string& tjtab, const int obverb, const int oblog, const uchar direkt/*=0*/)
{
	Log(violetts+Tx[T_pruefjtab]+schwarz,obverb,oblog);
	const size_t aktc=0;
	if (!direkt) {
		Feld felder[] = {
			Feld("eind","int","10","",Tx[T_eindeutige_Identifikation],1,1),
			Feld("Typ","decimal","2","0",Tx[T_Anruftyp_1_ankommend_3_abgehend],1,0,1),
			Feld("Datum","datetime","0","0",Tx[T_Zeitpunkt_des_Verbindungsaufbaus],0,0,1),
			Feld("Name","varchar","1","",Tx[T_Name_des_Verbindungspartners],0,0,1),
			Feld("Rufnummer","varchar","1","",Tx[T_Rufnummer_des_Verbindungspartners],0,0,1),
			Feld("Nebenstelle","varchar","1","",Tx[T_Nebenstelle_hier],0,0,1),
			Feld("EigeneNr","varchar","1","",Tx[T_Eigene_Rufnummer],0,0,1),
			Feld("Dauer","decimal","5","2",Tx[T_Verbindungsdauer],0,0,1),
		};
		Feld ifelder0[] = {Feld("Datum")};   Index i0("Datum",ifelder0,sizeof ifelder0/sizeof* ifelder0);
		Index indices[]={i0};
		// auf jeden Fall ginge "binary" statt "utf8" und "" statt "utf8_general_ci"
		Tabelle taba(My,tjtab,felder,sizeof felder/sizeof* felder,indices,sizeof indices/sizeof *indices,
				Tx[T_Telefonprotokoll_der_Fritzbox]/*//,"InnoDB","utf8","utf8_general_ci","DYNAMIC"*/);
		if (taba.prueftab(aktc,obverb)) {
			Log(rots+Tx[T_Fehler_beim_Pruefen_von]+schwarz+tjtab,1,1);
			exit(11);
		}
	} // if (!direkt)
} // int pruefjtab(DB *My, string touta, int obverb, int oblog, uchar direkt=0)

// wird aufgerufen in: main
int hhcl::initDB()
{
	Log(violetts+"initDB(), db: "+blau+dbq+schwarz);
	unsigned int fehler=0;
	if (dbq.empty()) {
		fehler=1046;
	} else {
		if (!My) {
			My=new DB(myDBS,linstp,host,muser,mpwd,maxconz,dbq,/*port=*/0,/*unix_socket=*/0,/*client_flag=*/0,obverb,oblog);
			if (My->ConnError) {
				delete My;
				My=0;
			} else {
				My->lassoffen=1;
			} // 			if (My->ConnError) else
		} // 		if (!My)
		fehler=My->fehnr;
	} // 	if (dbq.empty())
	if (fehler) {
		Log(rots+Tx[Verbindung_zur_Datenbank_nicht_herstellbar]+schwarz+ltoan(fehler)+rot+Tx[T_Breche_ab]+schwarz);
		return 1;
	} //   if (My->fehnr)
	return 0;
} // initDB

// wird aufgerufen in rueckfragen
int hhcl::pruefDB(const string& db)
{
	Log(violetts+Tx[T_pruefDB]+db+")"+schwarz);
	if (!My) {
		My=new DB(myDBS,linstp,host,muser,mpwd,maxconz,db,0,0,0,obverb,oblog,DB::defmycharset,DB::defmycollat,3,0);
		if (My->ConnError) {
			delete My;
			My=0;
		}else {
			My->lassoffen=1;
		}
	} // 	if (!My)
	return (My->fehnr); 
} // pruefDB


hhcl::hhcl(const int argc, const char *const *const argv):hcl(argc,argv)
{
} // hhcl::hhcl

hhcl::~hhcl()
{
} // hhcl::~hhcl

// wird aufgerufen in: rueckfragen, als virtualle Funktion von hcl::gcl0()
void hhcl::lgnzuw()
{
 hcl::lgnzuw();
 Txd.lgn=Tx.lgn=Txk.lgn;
} // void hhcl::lgnzuw

// wird aufgerufen in: main
void hhcl::getcommandl0()
{
 if (obverb) {
  cout<<violett<<"getcommandl0()"<<schwarz<<endl;
  obverb=0;
 }
 // Reihenfolge muss koordiniert werden mit lieskonfein und rueckfragen
 const char* const sarr[]={"language","host","muser","mpwd","datenbank"};
 agcnfA.initd(sarr,sizeof sarr/sizeof *sarr);
 gcl0();
} // getcommandl0

void hhcl::VorgbAllg()
{
 Log(violetts+Tx[T_VorgbAllg]+schwarz);
} // void hhcl::VorgbAllg

void hhcl::VorgbSpeziell()
{
 Log(violetts+Tx[T_VorgbSpeziell]+schwarz);
 MusterVorgb();
} // void hhcl::VorgbSpeziell

void hhcl::MusterVorgb()
{
 Log(violetts+Tx[T_MusterVorgb]+schwarz);
 dbq=DPROG;
 muser="user";
} // void hhcl::MusterVorgb

// wird aufgerufen in: main
void hhcl::lieskonfein()
{
 hcl::lieskonfein();
 lfd++;
 if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&host); else rzf=1; lfd++;
 if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&muser); else rzf=1; lfd++;
 if (agcnfA[lfd].gelesen) mpwd=XOR(string(agcnfA[lfd].wert),pwk); else rzf=1; lfd++;
 if (agcnfA[lfd].gelesen) agcnfA[lfd].hole(&dbq); else rzf=1; lfd++;
 setzlog();
 if (nrzf) rzf=0;
} // void hhcl::lieskonfein

//wird aufgerufen in: main
int hhcl::getcommandline()
{
 Log(violetts+"getcommandline()"+schwarz);
 opts.push_back(/*2*/optioncl(T_host_k,T_host_l,&Tx, T_verwendet_die_Datenbank_auf_Host_string_anstatt_auf,0,&host,psons,&agcnfA,"host",&obkschreib));
 opts.push_back(/*2*/optioncl(T_muser_k,T_muser_l,&Tx, T_verwendet_fuer_MySQL_MariaDB_den_Benutzer_string_anstatt,0,&muser,psons,&agcnfA,
			 "muser",&obkschreib));
 opts.push_back(/*2*/optioncl(T_mpwd_k,T_mpwd_l,&Tx, T_verwendet_fuer_MySQL_MariaDB_das_Passwort_string,0,&mpwd,psons,&agcnfA,"mpwd",&obkschreib));
 opts.push_back(/*2*/optioncl(T_db_k,T_datenbank_l,&Tx, T_verwendet_die_Datenbank_string_anstatt,0,&dbq,psons,&agcnfA,"datenbank",&obkschreib));
 opts.push_back(/*4*/optioncl(T_info_k,T_version_l, &Tx, T_Zeigt_die_Programmversion_an, 1, &zeigvers,1));
 opts.push_back(/*4*/optioncl(T_vi_k,T_vi_l, &Tx, T_Konfigurations_u_Logdatei_bearbeiten_sehen, 1, &obvi,1));
 opts.push_back(/*4*/optioncl(T_h_k,T_hilfe_l, &Tx, T_Erklaerung_haeufiger_Optionen, 1, &obhilfe,1));
 opts.push_back(/*4*/optioncl(T_lh_k,T_lhilfe_l, &Tx, T_Erklaerung_aller_Optionen, 1, &obhilfe,2));
 opts.push_back(/*4*/optioncl(T_fgz_k,T_fgz_l, &Tx, -1, 1, &obhilfe,1));
 // hier wird die Befehlszeile ueberprueft:
 for(;optslsz<opts.size();optslsz++) {
	 for(size_t i=0;i<argcmv.size();i++) {
		 if (opts[optslsz].pruefpar(&argcmv,&i,&obhilfe,Tx.lgn)) {
			 if (opts[optslsz].kurzi==T_cm_k) { // cronminuten
				 keineverarbeitung=1;
				 cmeingegeben=1;
			 }
			 else if (opts[optslsz].kurzi==T_mpwd_k) {
				 const string pwdstr=XOR(mpwd,pwk);
				 agcnfA.setze(string(Tx[T_mpwd_k]),pwdstr);
			 } // 				if (opts[optslsz].kurzi==T_mpwd_k)
			 break;
		 } //       if (opts[optslsz].pruefpar(&argcmv,&i,&obhilfe,Tx.lgn))
	 } // for(size_t i=0;i<argcmv.size();i++) 
 } //   for(;optslsz<opts.size();optslsz++)
 if (nrzf||obhilfe>2) rzf=0; // 3 oder 4
 for(size_t i=0;i<argcmv.size();i++) {
	 if (!argcmv[i].agef) {
		 ::Log(rots+"Parameter: "+gruen+argcmv[i].argcs+rot+Tx[T_nicht_erkannt]+schwarz,1,1);
		 if (!obhilfe) obhilfe=1;
	 } //     if (!argcmv[i].agef)
 } //   for(size_t i=0;i<argcmv.size();i++)
	stringstream erkl;
	erkl<<blau<<Tx[T_Liest_das_Fritzbox_Journal_Ueber_RogerRouter_aus_und_sammelt_es_in_einer_Datenbank]<<schwarz;
 if (zeighilfe(&erkl)) 
	 return 1;
	Log(violetts+Txk[T_Ende]+"getcommandline()"+schwarz);
 return 0;
} // int hhcl::getcommandline

// wird aufgerufen in: main
void hhcl::rueckfragen()
{
 Log(violetts+Tx[T_rueckfragen]+schwarz);
 if (rzf) {
  int lfd=-1;
  const char *const locale = setlocale(LC_CTYPE,"");
  if (langu.empty()) if (locale) if (strchr("defi",locale[0])) langu=locale[0];
  vector<string> sprachen={"e","d"/*,"f","i"*/};
  if (agcnfA[++lfd].wert.empty()||rzf) {
   langu=Tippstrs(sprachstr.c_str()/*"Language/Sprache/Lingue/Lingua"*/,&sprachen,&langu);
   lgnzuw();
   agcnfA[lfd].setze(&langu);
  } // if (agcnfA
	if (agcnfA[++lfd].wert.empty() || rzf) {
		host=Tippstr(Tx[T_Host_fuer_MySQL_MariaDB_Datenbank],&host);
		agcnfA[lfd].setze(&host);
	} //     if (agcnfA[++lfd].wert.empty() || rzf)
	if (agcnfA[++lfd].wert.empty() || rzf) {
		const string Frage=Tx[T_Benutzer_fuer_MySQL_MariaDB];
		muser=Tippstr(Frage.c_str(),&muser);
		agcnfA[lfd].setze(&muser);
	} //     if (agcnfA[++lfd].wert.empty() || rzf)
	if (agcnfA[++lfd].wert.empty() || rzf) {
		string mpw2;
		mpwd.clear();
		do {
			mpwd=Tippstr(string(Tx[T_Passwort_fuer_MySQL_MariaDB])+Txk[T_fuer_Benutzer]+dblau+muser+schwarz+"'",&mpwd);
			mpw2=Tippstr(string(Tx[T_Passwort_fuer_MySQL_MariaDB])+Txk[T_fuer_Benutzer]+dblau+muser+schwarz+"'"+" ("+Txk[T_erneute_Eingabe]+")",&mpw2);
		} while (mpwd!=mpw2);
		const string pwdstr=XOR(mpwd,pwk);
		agcnfA[lfd].setze(&pwdstr);
	} // 		if (agcnfA[++lfd].wert.empty() || rzf)
	if (agcnfA[++lfd].wert.empty() || rzf) {
		dbq=Tippstr(string(Tx[T_Datenbankname_fuer_MySQL_MariaDB_auf])+dblau+host+schwarz+"'",&dbq);
		agcnfA[lfd].setze(&dbq);
	} //     if (agcnfA[++lfd].wert.empty() || rzf)
 } // if (rzf)
} // void hhcl::rueckfragen()

// wird aufgerufen in: main
void hhcl::autokonfschreib()
{
	Log(violetts+Tx[T_autokonfschreib]+schwarz+", "+Tx[T_zu_schreiben]+((rzf||obkschreib)?Txk[T_ja]:Txk[T_nein]));
	if (rzf||obkschreib) {
		Log(gruens+Tx[T_schreibe_Konfiguration]+schwarz);
 } // if (rzf||obkschreib)
		schlArr *ggcnfAp[1]={&agcnfA};
		multischlschreib(akonfdt, ggcnfAp, sizeof ggcnfAp/sizeof *ggcnfAp, mpfad);
} // void hhcl::autokonfschreib

// wird aufgerufen in: main
void hhcl::zeigueberschrift()
{
 char buf[20]; snprintf(buf,sizeof buf,"%.5f",versnr);
 ::Log(schwarzs+Txk[T_Programm]+blau+mpfad+schwarz+", V: "+blau+buf+schwarz,1,1);
} // void hhcl::zeigueberschrift

void hhcl::pruefggfmehrfach()
{
	if (!obhilfe &&!obvi &&!zeigvers) {
		pruefmehrfach(meinname,nrzf);
	}
} // void hhcl::pruefggfmehrfach()

void hhcl::liescsv()
{
	const size_t aktc=0;
	string zeile;
	size_t dsz=0,egz=0;
	svec srueck;
	systemrueck("find /root/.local/share/routermanager -name journal.csv -printf '%T+\t%p\n'|sort -r|head -n1|cut -f2",obverb,oblog,&srueck);
	if (srueck.size()) csvs=srueck[0];
	mdatei csv(csvs,ios::in);
	if (csv.is_open()) {
		RS rins(My); 
		while(getline(csv,zeile)) {
			svec fld;
			aufSplit(&fld, zeile, ";");
			////			<<dsz<<": "<<violett<<zeile<<schwarz<<endl;
			tm vt({0});
			stringstream vts;
			for(unsigned iru=0;iru<fld.size();iru++) {
				if (iru==1) {
					strptime(fld[iru].c_str(),"%d.%m.%y %H:%M",&vt);
					vts<<put_time(&vt,"%Y-%m-%d %H:%M");
				}
			}
			if (fld.size()>3 and fld[0]!="Typ") {
				dsz++;
				string dauer=fld[6];
				ersetzAlle(dauer,":",".");
				RS such(My,"SELECT datum FROM `"+tjtab+"` WHERE typ="+fld[0]+" and Datum='"+vts.str()+"' and Name ='"+fld[2]+"'"\
						" and Rufnummer='"+fld[3]+"' and EigeneNr='"+fld[5]+"' and Dauer='"+dauer+"'",aktc,ZDB); // Nebenstelle wg. Zeichensatz weggelassen
				if (!such.obfehl) {
					char*** cerg=such.HolZeile();
					if (!cerg || !*cerg) {
						vector<instyp> einf; // fuer alle Datenbankeinfuegungen
						einf.push_back(/*2*/instyp(My->DBS,"Typ",fld[0]));
						einf.push_back(/*2*/instyp(My->DBS,"Datum",&vt));
						einf.push_back(/*2*/instyp(My->DBS,"Name",fld[2]));
						einf.push_back(/*2*/instyp(My->DBS,"Rufnummer",fld[3]));
						einf.push_back(/*2*/instyp(My->DBS,"Nebenstelle",fld[4]));
						einf.push_back(/*2*/instyp(My->DBS,"EigeneNr",fld[5]));
						einf.push_back(/*2*/instyp(My->DBS,"Dauer",dauer));
						caus<<"Fuege ein: "<<put_time(&vt,"%Y-%m-%d %H:%M")<<endl;
						rins.tbins(tjtab,&einf,aktc,/*sammeln=*/1,/*oberb=*/ZDB,/*idp=*/0,/*eindeutig=*/0);  // einfuegen
						if (!rins.fnr)
							egz++;
					} // 					if (!cerg || !*cerg)
				} // 				if (!such.obfehl)
			} // 			if (fld.size()>3 and fld[0]!="Typ")
		} // 		while(getline(csv,zeile))
		rins.tbins(tjtab,0,aktc,/*sammeln=*/0,/*oberb=*/ZDB,/*idp=*/0,/*eindeutig=*/0);  // einfuegen
	} // 	if (csv.is_open())
	::Log(blaus+ltoan(dsz)+schwarz+" Datensaetze gelesen",1,0);
	::Log(blaus+ltoan(egz)+schwarz+" Datensaetze eingetragen",1,0);
} // void hhcl::liescsv

int main(int argc,char** argv)
{
	hhcl hhi(argc,argv); // hiesige Hauptinstanz
	/*//
		if (argc>1) {
		} // (argc>1)
	 */
	hhi.getcommandl0(); // anfangs entscheidende Kommandozeilenparameter abfragen
	hhi.VorgbAllg();
	if (hhi.obhilfe==3) { // Standardausgabe gewaehrleisten
		hhi.MusterVorgb();
	} else {
		hhi.VorgbSpeziell(); // die Vorgaben, die in einer zusaetzlichen Datei mit einer weiteren Funktion "void hhcl::VorgbSpeziell()" ueberladbar sind
		hhi.lieskonfein();
	}
	if (!hhi.keineverarbeitung) {
		hhi.rueckfragen();
		hhi.pruefggfmehrfach();
	} // if (hhi.obhilfe==3)
	hhi.lieszaehlerein(&hhi.aufrufe,&hhi.tagesaufr,&hhi.monatsaufr,&hhi.laufrtag);

	if (hhi.getcommandline())
		exit(8);
	if (hhi.obvi) 
		hhi.dovi();
	if (hhi.zeigvers) {
		hhi.zeigversion();
		hhi.zeigkonf();
	} //   if (hhi.zeigvers)
	if (!hhi.keineverarbeitung) {
		if (hhi.initDB())
			return 10;
		pruefjtab(hhi.My,hhi.tjtab, hhi.obverb,hhi.oblog);
	} // 	if (!hhi.keineverarbeitung)
	systemrueck(sudc+"timeout -k 2s 60s roger_cli -j -d",hhi.obverb,hhi.oblog);
	hhi.liescsv();
	hhi.autokonfschreib();
	hhi.schlussanzeige();
	return 0;
} // int main

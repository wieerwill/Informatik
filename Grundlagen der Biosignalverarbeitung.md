Biosignalverarbeitung
- [Sensorik](#sensorik)
  - [Klassifikation von Sensoren](#klassifikation-von-sensoren)
  - [Druck, Dehnung und Kraft](#druck-dehnung-und-kraft)
  - [Durchfluss, Volumen](#durchfluss-volumen)
  - [Optische Sensoren](#optische-sensoren)
  - [Akustische Sensoren](#akustische-sensoren)
  - [Sensoren für elektrische Größen](#sensoren-für-elektrische-größen)
    - [Elektrochemische Grundlagen](#elektrochemische-grundlagen)
    - [Elektroden der Diagnostik](#elektroden-der-diagnostik)
    - [Elektroden der Therapie](#elektroden-der-therapie)
  - [Sensoren für magnetische Größen](#sensoren-für-magnetische-größen)
    - [Messprinzipien](#messprinzipien)
    - [Gradiometer](#gradiometer)
    - [SQUID](#squid)
- [Verstärkung und analoge Filterung](#verstärkung-und-analoge-filterung)
  - [Eigenschaften von Biosignalen und Störungen](#eigenschaften-von-biosignalen-und-störungen)
    - [Entstehung der Biosignale, biologische Signalquellen](#entstehung-der-biosignale-biologische-signalquellen)
    - [Biologische und technische Störquellen](#biologische-und-technische-störquellen)
      - [Eigenschaften technischer Störungen](#eigenschaften-technischer-störungen)
      - [Eigenschaften biologischer Störungen](#eigenschaften-biologischer-störungen)
  - [Medizinische Messverstärker](#medizinische-messverstärker)
    - [Dynamik, Linearität](#dynamik-linearität)
    - [Eigenrauschen](#eigenrauschen)
    - [Frequenzgang](#frequenzgang)
  - [Differenzverstärker](#differenzverstärker)
    - [Funktionsprinzip](#funktionsprinzip)
    - [Differenz- und Gleichtaktverhalten](#differenz--und-gleichtaktverhalten)
- [Signalkonditionierung, Abtastung und Digitalisierung](#signalkonditionierung-abtastung-und-digitalisierung)
- [Digitale Filterung](#digitale-filterung)

# Sensorik
Im Normalfall werden Sensoren verwendet, die eine physikalische oder chemische Größe in ein elektrisches Signal umwandeln bzw. eine elektrische Größe beeinflussen, die weiter verarbeitet werden können. Eine Umwandlung der Energieform der Biosignale ist notwendig. Selbst bei Sensoren für elektrische Größen ist eine Umwandlung (von Ionenleitung zur Elektronenleitung) nötig.

Weitere Sensorengruppen, wie Temperatur-und chemische Sensoren werden hier nicht behandelt, da ihre Dynamik aus Sicht der BSA vernachlässigbar gering ist.

## Klassifikation von Sensoren
Ein Sensor (lateinisch 'sensus': Gefühl) oder Fühler ist ein technisches Bauteil, das die physikalischen oder chemischen Eigenschaften (z.B. Wärmestrahlung, Temperatur, Feuchtigkeit, Druck, Schall, Helligkeit, Magnetismus, Beschleunigung, Kraft, elektrisches Potential) erfassen und in ein elektronisches oder ein anderes geeignetes Signal umwandeln kann.

Man unterscheidet zwischen aktiven und passiven Sensoren
- Aktiver Sensor: gibt eine Spannung oder einen Strom ab, wobei er für seine Funktion elektrische Energie benötigt oder eine Energieart in die elektrische umwandelt. Er wirkt wie eine elektrische Signalquelle (z.B. Phototransistor)
- Passiver Sensor: ändert elekttrische Größen (z.B. den Widerstand des Dehnmessstreifens in Abhängigkeit von der Dehnung) ohne Energiezufuhr von außen.

Auflösung von Sensoren:
- temporal: Zeitabstand zwischen Messungen (z.B. Geigerzähler, Aktionspotentiale)
- spektral: Abstand von Spektrallinien (z.B. Wärmebildkamera, Infrarotsensor, Spektralphotometer)
- räumlich: räumlicher Abstand (z.B. EEG, Ultraschall, CT/MRT)
- und alle Kombinationen (z.B. spatialtemporale Auflösung in einem Frequenzband)

Klassifikation nach Messgröße:
- Physikalisch: Kraft, Druck, Moment, Durchfluss
- Elektrizität: Potential, Strom, Impedanz
- Magnetismus: Fluss, Induktion
- Optik/Licht: spektrale Dämpfung, Extinktion
- Chemisch: Partialdruck von Gasen, Zucker, Hämoglobin
- Akustik: Herzschalltöne, Atmung
- Temperatur: Körpertemperatur

## Druck, Dehnung und Kraft
Dehnmessstreifen (DMS)
- Messprinzip: Dehnungsabhängiger Widerstand
- Realisierung: Widerstandsdraht oder Halbleiter als Gitter auf Träger
- Messbare Größen: Kraft, Druck, Moment
- Anwendung in der Medizintechnik: Atmungsdiagnostik, Fahrradergometer, Diagnostik des Bewegungsapparates
- Signaleigenschaftem
  - passiver Sensor - thermisches und/oder Halbleiter-Rauschen
  - empfindlich gegen NF-elektrische/magnetische und HF-elektromagnetische Felder
  - temperaturabhängig vor allem Halbleiter
  - Übertragungseigenschaften abhängig von der Sensorkopplung
  - Signaldynamik abhängig von Masse und Technologie

Grundlage ist der piezoresestive Widerstandseffekt: Durch Zug/Druck nimmt der elektrische Widerstand zu/ab
- $R=\ro\frac{l}{A}=\ro\frac{4l}{d^2\pi}$, $\ro$ spez. Widerstand, $l$ Drahtlänge, $d$ Drahtdurchmesser
- $R+\delta R=(\ro+\delta\ro)\frac{4(l+\delta l)}{(d-\delta d)^2\pi}$; davon ist $(l+\delta l)$ relevant für die Dehnungsmessung


Die Widerstandsänderung ist linear abhängig von der Temperaturabhängigkeit des spez. Widerstandes, jedoch nicht linear abhängig von der mechanisch bedingten Änderung der
Abmessungen. Natürlich hängen die Längenänderung und die des Durchmessers zusammen. Der konkrete Zusammenhang ist jedoch durch die Konstruktion und das Material gegeben und kann nicht verallgemeinert werden. Da für die Messung allein die Längenänderung von Interesse ist, wird im weiteren nur diese betrachtet.

- $\frac{\delta R}{R}=k\frac{\delta l}{l}=k*\epsilon$, $\epsilon$-relative Dehnung
- $\epsilon=\frac{F}{EA}$, $F=\frac{\delta R}{R}*\frac{EA}{k}$, E-Elastizitätsmodul
- In der Praxis aus Kostengründen und wegen geringer Temperaturabhängigkeit meistens Konstant an (54% Cu, 45% Ni, 1% Mn mit $k=2,05$) verwendet

Messverfahren: Widerstandsmessung mit Brückenschaltung
- Wheatstone'sche Brücke: $U_A\rightarrow 0|_R \Rightarrow \frac{R_x}{R_V}=\frac{R_2}{R_1}$
- $R_X=R_V\frac{R_2}{R_1}$
- ![](./Assets/Biosignalverarbeitung-wheatstone-brücke.png)
- Warum wird Rx mit Wheatstone-Brücke und nicht klassisch über Stromeinspeisung und Spannungsmessung bestimmt?
  - Das Messsignal (Ua) ist stärker bzw. die Empfindlichkeit der Messanordnung ist höher als bei einer reinen Strom/Spannungsmessung, außerdem ist Temperaturkompensation möglich. 
  - Starkes Messsignal ist sinnvoll wegen der immer vorhandenen Störungen vom Netz und Leitungen, die direkt auf die Kabel der Messanordnung wirken.

Folien-DMS:
- Widerstandsdraht mit ca $20\mu m$ Durchmesser oder Halbleiter
- Träger Acrylharz, Epoxydharz, Polyamid
- ![](Assets/Biosignalverarbeitung-folien-dms.png)

Dehnungsmessrosette:
- Messung in drei Richtungen
- ![](Assets/Biosignalverarbeitung-Dehnungsmessrosette.png)

Wie man an diesen Konstruktionsbeispielen gut erkennen kann, bilden die Leitungen ungewollterweise eine Antenne, die alle vorhandenen Störungen aus der Umgebung aufnimmt, vor allem Netzeinstreuung, Mobilfunk und Computernetze.

Aufbau von Massebezogenen und Massefreien Messungen:
![](Assets/Biosignalverarbeitung-masse-messung.png)

Messspannung von $U_{R5}$ in der massebezogenen Schaltung
![](Assets/Biosignalverarbeitung-messspannung-massebezogen.png)
Bei massebezogener Messung - auch Single-End genannt, da gegen Masse - werden die Störungen direkt dem Messsignal überlagert, so dass später eine Trennung ohne aufwendige Signalverarbeitung kaum möglich ist.

Massebezogne eBrückenspannung (rot, blau) und Indikatorspannung $U_d$ (grün)
![](Assets/Biosignalverarbeitung-massebezogen-brückenspannung.png)
Einen großen Teil der Netzstörung bilden die elektrostatischen (kapazitiv eingekoppelten) Felder, die Gleichtaktcharakter haben. Diese lassen sich also durch Differenzbildung -hier mit einer Wheatstonschen Brücke -zum Teil eliminieren.

## Durchfluss, Volumen
- Massendurchfluss
  - $\dot m=\frac{dm}{dt}$
  - $[\dot m]=\frac{kg}{h};\frac{g}{s}
  - industriell relevante Größe, z.B. Kraftstoffe, Luftverbrauch im Motor
- Volumendurchfluss
  - $\dot V=\frac{dV}{dt}$
  - $[\dot V]=\frac{m^3}{h};\frac{l}{min}$
  - wichtige Messgröße in der medizinischen Messtechnik: Blutfluss, Atmung, Gastrointestinalapparat
- Der Durchfluss eines Mediums ist eine der wichtigsten Größen in der technischen und medizinischen Messtechnik. Technisch vor allem der Massendurchfluss, medizinisch der Volumendurchfluss, da medizinisch grundsätzlich die Volumina diagnostisch relevante Größe darstellen.
- Bei bekannter durchflossener Fläche wird der Volumenfluss über die Geschwindigkeitsmessung ermittelt
  - $\dot V=\frac{dV}{dt}=\frac{A*dl}{dt}= A*v$
  - Reale Verteilung der Geschwindigkeit ist Parabel mit Maximum in der Mitte $\rightarrow$ Gemessene Geschwindigkeit ist die mittlere Geschwindigkeit
- In der Medizin kann weder eine Geschwindigkeitsverteilung - wie in der Technik - erzwungen werden, noch kann sie vollständig erfasst werden. Daher misst man tatsächlich nur eine ,,mittlere'' Geschwindigkeit, wobei der Begriff ,,mittlere'' hier nicht ganz korrekt ist, da die tatsächliche Verteilung nach wie vor unbekannt ist.
- Messprinzip Druckdifferentmessung nach Gesetz von Hagen-Poiseuille
  - $\dot V=\frac{dV}{dt}\frac{\pi d^4}{128\mu}*\frac{\delta p}{l}$
  - $d$ - Durchmesser der Kappilare
  - $\delta p=p_A - p_B$ - Druckdifferenz über der Kapillare, abhängigkeit von der Strömungsgeschwindigkeit
  - $l$ - Länge der Kapilalre
  - $\mu$ - Viskosität des Mediums
  - ![](Assets/Biosignalverarbeitung-pneumotachograph.png)
  - Bsp: 10% Verengung der Kapillare $\rightarrow$ 34% Reduktion des Durchsatzes, d.h. im Blutkreislauf Anstieg des Blutdrucks um 34%
  - Bei externen Sensoren der Durchflussmessung kann man die Messbedingungen relativ klar vorgeben, z.B. im Pneumotachographen. Man erzwingt kapillare Strömung, der Strömungswiderstand und die Fläche sind bekannt, so dass aus der Druckdifferenz direkt auf den Durchfluss geschlossen werden kann.
- Anwendung in der Medizintechnik
  - Messung aller vitaler Lungenvolumina
  - Messung des Blutflusses
- Nachteile des Messprinzips
  - zusätzlicher Strömungswiderstand verfälscht das Ergebnis
  - bei Temperaturunterschieden Kappilaren-Medium Tröpfchenbildung
  - geringer Dynamikbereich (1:10)
  - niedrige Messgenauigkeit wegen Turbulenzen an Kapillarenden
  - direkter Kontakt mit Medium
- Ultraschall-Geschwindigkeitsmessung nach dem Laufzeitverfahren
  - $v=\frac{T_2-T_1}{T_1 T_2}*\frac{L}{2\ cos\ \alpha}$
  - $v$ - mittlere Strömungsgeschwindigkeit des Mediums
  - $T_1$ - Laufzeit des Ultraschalls mit der Strömung
  - $T_2$ - Laufzeit des Ultraschalls gegen die Strömung
  - $L$ - Länge des Ultraschall-Pfades
  - $\alpha$ - Winkel zwischen der Strömung und dem Ultraschall-Pfad
  - ![](Assets/Biosignalverarbeitung-ultraschall-geschwindigkeit.png)
  - Vorteile
    - kein Kontakt mit dem Medium, insbesondere Blutbahnen
    - Installation und Messung ohne Unterbrechnung des Flusses
  - Nachteile
    - invasive Methode, da Blutgefäß freigelegt werden muss
    - Ungenauigkeit wegen der Verfomung der Blutgefäße
  - Signaleigenschafte
    - verrauscht wegen Streuung im Medium, Sensorrauschen
    - Echo statisch verteilt wegen Geschwindigkeitsprofil
- Ultraschall-Geschwindigkeitsmessung nach dem Dopplerverfahren
  - $f_D=f\frac{c}{c-v} \Rightarrow v=c\frac{f-f_D}{f_D}$
  - $c$ - Ausbreitungsgeschwindigkeit des Ultraschalls im Medium
  - $f$ - Originalfrequenz der Signalquelle
  - $f_D$ - gemessene Frequenz (Beobachter)
  - $v$ - Geschwindigkeit der Signalquelle
  - ![](Assets/Biosignalverarbeitung-ultraschall-doppler.png)
  - ![](Assets/Biosignalverarbeitung-ultraschall-doppler-2.png)
  - Anm: Feste Blutbestandteile (Blutkörperchen) reflektieren die Schallwellen und sind somit für den Ultraschall-Empfänger bewegte Signalquellen
- signalanalytisch relevante Eigenschaften
  - Flussgeschwindigkeit ungleichmäßig verteilt
  - im technischen Bereich konstruktiv beherrschbar (Messkammer, Durchmesser, Material)
  - im medizinischen Bereich kein Einfluss auf die Gefäße, daher relativ ungenaue Messung der mittleren Geschwindgkeit

## Optische Sensoren
Optische und Strahlungsquellen
- Kaltlichtquelle: in der Endoskopie, bläuliches Tageslicht wegen der Farbtreue
- Diagnostische Laser: in der Ophthalmologie, Urologie, inneren Medizin, Dermatologie
- Leuchtdioden: in der Photoplethysomographie (Pulsoximetrie)
- Röntgen-, Gamma-, UV- und IR-Strahler: in der diagnostischen Bildgebung
- Inspektionslicht: in der HNO (Halogenstrahler)

Signalanalytisch wichtige Eigenschafte
- Temperaturstrahler: sind träge, daher statisches, konstantes Licht
- Halbleiter (Leuchtdioden), Laser und Leuchtstoffröhren sind gepulste Quellen - mit dem Auge nicht wahrnehmbar, aber analytisch unter Umständen sehr problematisch

Optische Sensoren
- Phototransistor: in Flachbilddetektoren der Radiologie
- Kamerachips: in den Endoskopen
- Szintillatoren: in Gamma-Kameras
- Photovervielfacher (SEV) in Laser-Fluroszenzsystemen

Sensoreigenschaften
- starkes Eigenrauschen, typisch für Halbleiter, ,,Dunkelstrom''
- hohe Temperaturabhängigkeit, ist materialbedingt, variable Parameter
- ungünstige Dynamikeigenschaften, Nachleuchten durch Trägheit, systemanalytisch lange Impulsantwort

Beispiel Optischer Sensor CMOS Kamera LOGLUX i5
- wahlfreier Pixelzugriff
- CameraLink oder FireWire Datenschnittstelle
- Auflösung 1280x1024 Pixel, 10 bit Graustufen
- $>100$ dB Kontrast-/Dynamikumfang
- ca 36 fps bei Vollbild; höhere Bildrate bei kleinerem Bildfeld bis ca 1500 fps
- Vorverarbeitung der Bilddaten mittels integrierter LUT (look-up-tables) möglich
- spektraler Arbeitsbereich 400-1000nm

Optische Messmethoden gewinnen in der Medizin immer mehr an Bedeutung, vor allem, weil sie nichtinvasiv sind und daher patientenfreundlich. Mit der Kombination von Spektralfotometrie und Photoplethysmografie kann die Sauerstoffsättigung bestimmt werden. Dazu ist es notwendig, Gewebe durchzustrahlen, welches mit arteriellem Blut versorgt wird. Sehr verbreiten ist die Transmissionsmessung -d.h., das Gewebe wird durchstrahlt, was den Anforderungen an eine Messanordnung entsprechend der Theorie noch am nächsten kommt. Eine Alternative wurde notwendig, da der Finger u.U. nicht versorgt wird, z.B. beim Schock: Die Reflexionsmessung, bei der das Licht über einem Flächenknochen eingestrahlt und das reflektierte erfasst wird.
- ![](Assets/Biosignalverarbeitung-pulsoxy-1.png)
- ![](Assets/Biosignalverarbeitung-pulsoxy-2.png)
- ![](Assets/Biosignalverarbeitung-pulsoxy-3.png)

Signal am Photodetektor
- Multiplex bzw. sequentielle Abtastung
- Rauschen (Optoelektronik)
- Umgebungslicht, insbesondere Leuchtstoffröhren
- ![](Assets/Biosignalverarbeitung-pulsoxy-4.png)

Signal am Demultiplexer
- DC ca 95-98%
- AC nach DC Subtraktion verstärkt
- ![](Assets/Biosignalverarbeitung-pulsoxy-5.png)

Für die Signalverarbeitung bedeutet die Analyse des empfangenen Signals eine komplexe Herausforderung: Die Störungen, das Rauschen und das Umgebungslicht (vor allem im OP), sind enorm stark, so dass ihre Trennung vom Signal schwierig ist. Hinzu kommt, dass das Nutzsignal im unteren Prozentbereich des gesamten empfangenen Signals liegt, so dass hier das SNR um weitere zwei Dekaden schlechter wird.

An diesem Beispiel eines realen Pulsoximetriesignals kann man die realen Eigenschaften erkennen: 
- ![](Assets/Biosignalverarbeitung-pulsoxy-6.png)
  - Der DC-Anteil, der im Grunde durch eine Tiefpassfilterung gewonnen wird, ist real ein stark schwankender gleitender Mittelwert (unterer Verlauf).
  - Der AC-Anteil (oberer Verlauf) zeigt ebenfalls starke Schwankungen. Um dem Mediziner einen einigermaßen stabilen Messwert zu bieten, sind mehrere Schritte der SV notwendig
- ![](Assets/Biosignalverarbeitung-pulsoxy-7.png)
  - Pulsbreite 1ms, analoger Tiefpass 10kHz, Abtastrate 10 ksps
  - Zunächst müssen aus dem Multiplexsignal die aktuellen Signalpegel für das rote und infrarote Licht sowie für das Umgebungslicht gewonnen werden: Durch die 10fache Überabtastung stehen für Rot und Infrarot zunächst elf Messwerte zur Verfügung. Dieser Umfang an Messdaten ist für eine Pegelbestimmung mit dem Mittelwert zu gering, daher wird der Median verwendet. Nach der Medianbildung liegen die Signalpegel für weitere Berechnung vor.
- ![](Assets/Biosignalverarbeitung-pulsoxy-8.png)
  - Die gewonnenen Signalpegel werden nun einer Signalanalyse unterzogen. Die Analyse bei einer Wellenlänge ist ausreichend, da die Signalform bei allen qualitativ identisch ist. Für die Bestimmung des AC-Pegels werden die Extrema detektiert. Aus der Physiologie ist bekannt, dass die Anstiegszeit der Pulswelle höchstens 30% der Gesamtzeit beträgt, so dass eine Prüfung im Zeitfenster folgt. Weiterhin ist der Bereich der Periode bekannt, diese Prüfung folgt im nächsten Schritt. Durch Artefakte, vor allem durch Bewegung, entstehen Schwankungen der Basislinie. Nach einem empirische ermittelten Kriterium wird ein Trend von bis zu 30% vor der Berechnung akzeptiert.

## Akustische Sensoren
Physiologischer Schall (Herztöne, Atmungsapparat) liegt im hörbaren Bereich, so dass hier Methoden eingesetzt werden, die aus der allgemeinen Akustik bekannt sind. 
Konventionelle Mikrophontechnik mit spezifischer Signalverarbeitung
- Verstärkung im tieffrequenten Bereich mit linearer Phase
- Richtcharakteristik umschaltbar bzw einstellbar, mechanisch bereits in den ältesten Stetoskopen
- spektrale Filterung für typische Geräusche, wie Herzklappen, Pfeifen in der Lunge, etc
- Merkmalserkennung in computerbasierter Auswertung, Mustererkennung typischer pathologisch bedingter Geräusche

Beim Ultraschall (CW,PW,Doppler) handelt es sich um mechanische Schwingungen bis in den zweistelligen Megahertzbereich ( ca. 30MHz). Hier müssen aufwendige Methoden der SV angewandt und entwickelt werden, die primär -d.h. bis zum Übergang in den physiologischen Bereich bzw. zur Bildgebung -eher in der Nachrichtentechnik und Stochastik ihren Ursprung haben: Signaldetektion, Korrelationsrechnung, Histogramme, Signalzerlegung. 
Signalanalytisch wichtige Eigenschaften:
- bei CW (Continous Wave) keine Tiefeninformation verfügbar, Information über Dopplerfrequenz mit hoher Variationsbreite, stochastischer Charakter mit viel Rauschen
- bei PW (pulsed Wave) Auflösung von der Signalverarbeitung entscheidend abhängig, da physikalische Grenzen lange erreicht
- in der Doppler-Technologie beides (CW und PW) vereint, daher Summe aller Vor- und Nachteile

## Sensoren für elektrische Größen
### Elektrochemische Grundlagen
- Dieser Sensortyp dient der Erfassung der elektrischen Aktivität des Menschen
- Der Mensch produziert elektrische Signale, daher ist keine Umwandung der Energieform notwendig
- Der Mensch ist elektrisch gesehen ein Volumentleiter der 2. Art - ein Elektrolyt oder ein Ionenleiter
- Das Messsystem ist mit metallischen Leitern aufgebaut - Leiter der 1. Art, Elektronenleiter
- daher ist die Schaffung einer Schnittstelle notwendig - die Elektrode
- ![](Assets/Biosignalverarbeitung-elektrochemische-grundlage.png)
  - $mM \Leftrightarrow mM^+ + me^-$
  - $K_k A_a\Leftrightarrow kK^+ + aA^-$
  - $\leftarrow$: Reduktion; $\rightarrow$: Oxidation
  - Dynamisches Gleichgewicht an den Phasengrenzen
  - An der Phasengrenze der beiden Leitertypen entwickelt sich -ähnlich wie in einem Halbleiter -eine Raumladungszone. Die freien Elektronen im Metall und die Kationen des Elektrolyts ziehen sich an und bilden an der Grenze eine Doppelschicht. Je nach der chemischen Zusammensetzung des Elektrolyts und des Metalls finden unterschiedlich starke chemische Reaktionen statt, die beim dynamischen Gleichgewicht die sog. Elektrodenspannung bilden. Funktionell handelt es sich hierbei also um ein ungewolltes Voltaisches Element.

### Elektroden der Diagnostik
- aus signalanalytischer Sicht Eingangsdaten
- aus messtechnischer Sicht Systemeingang

Ziele | Realisierbarkeit
--- | ---
geringe Elektrodenspannung | durch Materialwahl (AgAgCl)
geringer Drift der Elektrodenspannung | physiologisch bedingt, daher kaum beeinflussbar
geringes Eigenrauschen | Materialwahl und Technologie

Aus signalanalytischer Sicht sind die Ziele ganz klar vorgegeben. In der Praxis muss jedoch immer ein Kompromiss zwischen diesen Zielen und den Anforderungen der Anwendung und Praktikabilität gefunden werden: Wie diese Beispiele zeigen, hängt die Konstruktion der Elektrode von ihrer Bestimmung ab und daraus ergeben sich auch die Signaleigenschaften. So z.B. muss eine subkutane EMG-Elektrode die Form eine Nadel haben und aus einem Edelmetall sein. Dies hat zur Folge, dass die EMG-Elektroden relativ schlechte Signaleigenschaften aufweist: Riesige Elektrodenimpedanz (bis einige MOhm), stark kapazitives Verhalten, sehr hohe Elektrodenspannung (bis in den Voltbereich). Im Vergleich dazu haben die EKG-Elektroden -vor allem auf Grund ihrer großen Fläche und des Materials (AgAgCl, NaCl) -sehr günstige Eigenschaften: Niedrige Elektrodenimpedanz (kOhm-Bereich), sehr tieffrequent (bis DC), niedrige Elektrodenspannung (um 100 mV).

![](Assets/Biosignalverarbeitung-elektroden.png)

### Elektroden der Therapie
- aus signalanalytischer Sicht Ausgangsdaten
- aus messtechnischer Sicht Systemausgang

Ziele | Realisierbarkeit
--- | --- 
geringe Impedanz | durch Materialwahl (beschichtet Cu)
geringer Drift der Impedanz | physiologisch bedingt
Langzeitstabilität | Materialwahl und Technologie

Ebensowichtig wie die Eigenschaften der diagnostischen Elektroden, sind es auch die der therapeutischen Elektroden. Dies liegt darin begründet, dass die Therapie von den zuvor analysierten diagnostischen Daten abhängt -natürlich im signalanalytischen Sinne, denn medizinisch ist es immer so. Man muss sich also bei der gewählten Therapie darauf verlassen können, dass das, was man auf die Elektrode schickt, so auch am biologischen Objekt ankommt. Diese Forderung technologisch umzusetzen ist ungleich leichter als bei diagnostischen Elektroden, denn hier können relative große Flächen mit gutem Kontaktmaterial verwendet werden.

![](Assets/Biosignalverarbeitung-elektrode-therapie.png)

## Sensoren für magnetische Größen
### Messprinzipien
Um einen Eindruck über die Signalstärke (eher Signalschwäche) der biomagnetischen Signale zu bekommen, wird mit dem natürlichen Erdfeld verglichen, obwohl dieses für den Biomagnetismus eigentlich gar kein Problem darstellt. Störend sind die vom Menschen gemachten magnetischen Felder, vor allem die vom Stromversorgungsnetz, die jedoch weit über dem magnetischen Erdfeld liegen.
1. Das stärkste Biosignal, das MKG, liegt 6 Dekaden unter dem Erdfeld (120dB), und weitere 2...3 Dekaden unter den technischen Feldern.
2. MEG -7 Dekaden, oder 140dB,
3. evozierte Felder -8 Dekaden oder 160dB

- $10^0T$: MR-Tomographie-Magnete
- $10^{-5}T$: Erdfeld
- $10^{-6}T$: Zivilisationsfelder (Rauschen)
- $10^{-9}T$: magn. Kontamination der Lunge
- $10^{-10}T$: Magnetkardiogramm
- $10^{-12}T$: Magnetoenzephalogramm
- $10^{-13}T$: evozierte kortikale Aktivität
- $10^{-15}T$: SQUID System Rauschen

Biomagnetische Signale sind sehr schwach (SNR< -120dB). Mehrere Maßnahmen zur SNR-Anhebung notwendig
- Abschirmung des Messkreises gegen Störfelder (dickwandige Kammer aus $\mu$-Metallen)
- Ausnutzung der Feldeigenschaften - Gradiometer
- Spezialtechnologie der Signalverstärker - SQUID

### Gradiometer
Prinzip:
- Störfelder meist ferne Quellen, Biologische Strukuren nahe Quellen
- ferne Quellen produzieren annährend homogenes Feld
- nahe Quellen Produzieren inhomogenes Feld
- mit Gradiometer wird die erste bzw zweite räumliche Ableitung gebildet, dadurch wird homogenes Störfeld unterdrückt
- ![](Assets/Biosignalverarbeitung-Gradiometer.png)
- ![](Assets/Biosignalverarbeitung-gradiometer-2.png)
- homogenes Fernfeld (Störung, blau): $u=u_2-u_1=0$
- inhomogenes Nahfeld (Biosignalquelle, rot): $u=u_2-u_1<>0$

### SQUID
![](Assets/Biosignalverarbeitung-squid.png)

Das supraleitende Quanteninterferenzgerät (SQUID) besteht aus zwei Supraleitern, die durch dünne Isolierschichten getrennt sind und zwei parallele Josephson-Kontakte bilden. Das Gerät kann als Magnetometer konfiguriert werden, um unglaublich kleine Magnetfelder zu erkennen - klein genug, um die Magnetfelder in lebenden Organismen zu messen. SQUID wurden zur Messung der Magnetfelder in Mäusehirnen verwendet, um zu testen, ob ihr Magnetismus ausreicht, um ihre Navigationsfähigkeit auf einen inneren Kompass zurückzuführen. [Quelle](http://hyperphysics.phy-astr.gsu.edu/hbase/Solids/Squid.html)

# Verstärkung und analoge Filterung
## Eigenschaften von Biosignalen und Störungen

### Entstehung der Biosignale, biologische Signalquellen
- Analysegegenstand: Sensorisches, motorisches und zentrales Nervensystem
- Grundbaustein: Nervenzelle, Neuron. Einzelne Neurone kaum untersuchbar, im Einzelfall mit Mikroelektroden, dennoch für die Gesamtheit wenig Bedeutung. Wichtiger sind Untersuchungen an Neuronenverbänden und -strängen, z.B. motorische Steuerung von Muskeln in den Extremitäten. Hier haben die Nerven überschaubare und anatomisch sowie elektrophysiologisch gut bekannte Struktur.
- am Neuronausgang - Axon: Aktionspotentiale
- am Neuroneingang - Synapsen: EPSP/IPSP (exzitatorische und inhibitorische postsynaptische Potentiale)

- Sensorisches System ist deutlich komplexer, vor allem das akustische und das visuelle. So hat die Retina allein mehrere Millionen Sensoren (Stäbchen und Zapfen), die mit Ganglienzellen verbunden sind und bereits vor Ort relativ einfache Informationsverarbeitung durchführen.
- Zahlenmäßig und daher in auch in seiner Komplexität ist das größte das zentrale Nervensystem (ZNS), das aus ca. 10 Milliarden Neuronen besteht, die funktionelle und anatomische Zentren bilden aber zeitlich stark variierende Eigenschaften aufweisen.
- Signalanalytisch ist das Grundelement das Aktionspotential (AP), das vom Neuron nach Erreichen der Reizschwelle an seinen Eingängen über das Axon nach außen bzw. an andere Neurone abgegeben wird. Die Synapsen empfangen die Aktionspotentiale von anderen Neuronen und bewerten diese je nach Zustand mit EPSP oder IPSP, die von sich aus starken Veränderungen unterliegen. Im EEG sind die AP deutlich unterrepräsentiert (nur etwa 10% des EEG), wesentlicher Anteil bilden die PSP. Dies ist unter anderem durch den Tiefpasscharakter des Schädels bedingt, das die hochfrequenten AP unterdrückt.

![](Assets/Biosignalverarbeitung-ekg.png)

Ein medizinisch und auch signalanalytisch besonders interessantes Signal ist das EKG: Medizinische Indikation ergibt sich allein aus der besonderen Stellung des Herzens in der Physiologie als des Motors des Kreislaufs. Signalanalytisch ist es deswegen interessant, da es unter reproduzierbaren Messbedingungen (Extremitätenableitungen) formkonstanten Signalverlauf zeigt. Das EKG wurde entsprechend seiner elektromedizinischen Bedeutung extensiv untersucht, zahlreiche Erkrankungen und Schäden werden anhand typischer Formveränderungen des EKG diagnostiziert. Die Signalquelle des EKG ist das räumlich zwar recht komplizierte, aber anatomisch qualitativ konstante Reizleitungssystem des Herzens. Zur Ableitung des EKG werden standardmäßig 3-, 6-oder 12-kanalige Extremitäten-und Brustwandsysteme verwendet.

![](Assets/Biosignalverarbeitung-herz-ekg.png)

Projektion der Reizausbreitung auf einen längs zur Herzachse liegenden Vektor (vertikal): Zu beachten ist, dass durch die Differenzbildung an zwei Punkten an der Körperoberfläche damit mathematisch die erste räumliche Ableitung (oder auch der erste Gradient) gebildet wird. Das hat zur Folge, dass die Ableitung nicht nur in Phasen der Ruhe (vor der P-Welle), sondern auch bei maximaler Erregung ( PQ-und ST-Strecke) Null ist. Wellen und Zacken im EKG sind Ausdruck der räumlich-zeitlichen Veränderung im Reizleitungssystem.

![](Assets/Biosignalverarbeitung-gehirn.png)
![](Assets/Biosignalverarbeitung-gehirn-ekg.png)

Zur Ableitung des EEG werden wie beim EKG standardisierte Elektrodensysteme verwendet. Allerdings ist die anatomische Zuordnung hier ungleich schwieriger, denn die einzigen einigermaßen stabilen anatomischen Bezugspunkte sind das Nasion und das Inion. Es ist jedoch bekannt, dass die Lage des Gehirns in Bezug auf diese Punkte individuell stark unterschiedlich ist und im Zentimeterbereich liegt, so dass eine genaue Zuordnung der Elektroden zu Funktionszentren gar nicht möglich ist. Die Dichte der Elektroden in der Praxis liegt höchstens bei 10% NI, d.h. im Schnit bei etwa 3cm. Eine höhere Dichte bringt keine zusätzliche Information, da der Schädel als räumlicher Tiefpass funktioniert und keine höhere Auflösung erlaubt.

Aus Sicht der Signalanalyse ist es besonders wichtig zu wissen, unter welchen Messbedingungen das EEG abgeleitet wurde. Im Idealfall wird unipolar gegen verbundene Ohren oder Hals abgeleitet. Aus unipolaren Daten lassen sich die bipolaren Ableitungen einfach berechnen, umgekehrt geht das jedoch nicht. Auf jeden Fall ist zu klären, wie die Verschaltung des EEG-Verstärkers und der Elektroden realisiert wurde. Vermeintlich elegante Tricks, wie hardwaremäßige CAR sind auf jeden Fall zu meiden, ebenso Antialiasingfilter mit nichtlinearer Phase.

![](Assets/Biosignalverarbeitung-gehirn-eeg.png)

Das EEG wird in in fünf typische Bereiche unterteilt: delta (0..4Hz), theta (4-7Hz), alpha (8..13Hz), beta (13..30Hz), gamma (>30Hz). Diese Bereiche sind typisch für bestimmte physiologischen (Schlaf, Konzentration, Entspannung) und pathologischen Bilder. Für die Signalanalyse ist wichtig, dass die Bereiche nicht gleichzeitig vorhanden sind, einer ist immer dominant, was die Analyse leicht vereinfacht.


### Biologische und technische Störquellen
periodische | transiente
--- | ---
öffentliches Stromversorgungsnetz | Spannungsspitzen im Netz
Straßenbahn | Bewegungen im Messbereich
Monitore | Schaltvorgänge
Kommunikationsnetze | Lastschwankungen
Rotierende Maschinen |
Sender inkl. Funktelefon |

1.Das biomedizinische Messsystem ist von vielen Störquellen umgeben, die meisten sind dem Bereich der Medienversorgung, Industrie, Verkehr und Nachrichtentechnik zuzuschreiben. Für die BSA sind periodische (Versorgungsnetz, Monitore) und quasiperiodische (rotierende Maschinen, Straßenbahn) Störungen noch ein vergleichsweise geringes Problem, denn diese lassen sich gezielt mit spektralen Filtern in der analogen Messkette oder digital nach ADC unterdrücken.
2.Wesentlich schwieriger ist die Situation, wenn transiente Störungen vorliegen, denn diese haben im Allgemeinen einen unbekannten, einmaligen und daher nicht reproduzierbaren Verlauf. Solange die transiente Störung die Signalerfassung nicht beeinträchtigt (durch Übersteuerung des Messverstärkers) und deutlich von der Signalform abweicht (z.B. Ausgleichsvorgang mi EKG), kann sie mit relativ einfachen Mitteln beseitigt werden, dennoch im Allgemeinen ist dies kaum möglich.

![digitale Bandsperre für die Netzfrequenz](Assets/Biosignalverarbeitung-netzfrequenz-bandsperre.png)
Die häufigste -weil immer vorhanden- ist die Netzstörung. Selbst batteriebetriebene portable Messgeräte sind von dieser Störung betroffen. Da die Frequenz der Störung aber bekannt ist, kann sie -falls keine Übersteuerung vorliegt- mit einer Bandsperre reduziert werden. Allerdings sollte nicht die früher übliche ,,50 Hz -Filter'' Taste verwendet werden, denn diese Filter haben einen nichtlinearen Phasenfrequenzgang und können das Biosignal deutlich verfälschen. Bei der heutigen Technologie werden ausschließlich digitale Filter verwendet.

![Trendelimination (Hochpassfilterung)](Assets/Biosignalverarbeitung-trendelimination.png)
Eine sehr häufige transiente Störung im medizinischen Bereich ist die Bewegungsartefakte. Jegliche Bewegung im Messbereich erzeugt in der empfindlichen medizinischen Messtechnik Ausgleichsvorgänge. Wenn die Signalform gut bekannt ist, wie z.B. beim EKG, so lässt sich eine langsame Artefakte durch Hochpassfilterung beseitigen.
- Maximal $f_{0,01}=0,5 Hz$ Patienten-Monitor EKG (nicht oberhalb)
- Maximal $f_{0,02}=0,05Hz$ Diagnostischer Monitor bei EKG (nicht oberhalb)

Ob ein Biosignal gewollt ist oder eine Störung darstellt, ist von der Messaufgabe abhängig:
- soll das EKG gemessen werden, ist das EMG eine Störung
- soll das EEG gemessen werden, ist das EKG eine Störung
- soll das EOG gemessen werden, ist das EEG eine Störung

Prinzipielles Problem: Biologische Störquellen lassen sich nicht abschalten und kaum unterdrücken

Aus Sicht der BSA gestaltet sich das Problem der Störungen wesentlich schwieriger als bei technischen Störungen. Erstens, die Biosignalquellen befinden sich innerhalb des Körpers, daher können sie weder abgeschirmt noch abgeschaltet werden. Zweitens, das biologische Signalspektrum ist für alle Biosignale in etwa gleich, streckt sich von 0 bis etwa 1kHz aus und weist ein Maximum bei etwa 100Hz auf. Daher können biologische Störsignale mit spektralen Filtern allein nicht beseitigt werden.

Ein weiteres -messmethodisches -Problem besteh darin, dass man Biosignale nicht pauschal in Nutz-und Störsignale trennen kann. Es ist vielmehr die Messaufgabe, an Hand der man diese Klassifikation vornehmen muss.

#### Eigenschaften technischer Störungen
periodische Störungen | transiente Störungen
--- | ---
NF-magnetische Felder nicht eliminierbar durch Schirmung, erzeugen Differenzspannung | kaum eliminierbar, da Signalform unbekannt und nicht reproduzierbar
NF-elektrische Felder gut beherrschbar, erzeugen Gleichtaktstörungen | bestenfalls Detektion möglich, Messdaten nicht korrigierbar
HF-Felder immer mehr vorhanden (Kommunikationsnetze), Abschirmung unwirtschaftlich |

1. Naturgemäß erzeugen niederfrequente magnetische Felder am Verstärkereingang Differenzspannungen, die direkt mit dem Biosignal überlagert werden, so dass sie mit der üblichen Verstäkertechnik nicht reduziert werden können. Hinzu kommt, dass auch eine Abschirmung nicht viel bringt, da in diesem Frequenzbereich mehrere 10- Zentimeter dicke Eisenplatten verwendet werden müssten, was in der Praxis nicht realisierbar ist. Da die niederfrequenten elektrischen (kapazitiv eingekoppelten) Störfelder Gleichtaktsignale sind, können sie zum Teil gut durch die Differenzverstärkertechnik reduziert werden. In immer höheren Maße stören hochfrequente Felder, vor allem aus dem Mobilfunk, Datennetzen, WLAN, Bluetooth, etc. Eine Abschirmung ist im normalen Praxisbetrieb unwirtschaftlich, so dass eine Reduktion der Störung allein durch Maßnahmen der EMV zu erreichen ist.
2. Wie schon erwähnt, transiente Störungen sind im Grunde nicht beherrschbar, da sie eigentlich nicht bekannt und nicht vorhersehbar sind. Mit Methoden der BSA ist zum Teil ihre Detektion möglich, wenn z.B. der Messbereich oder das Spektrum des Biosignals nachweislich verlassen wird. Diese Detektion kann allerdings nur dazu genutzt werden, die beeinträchtigten Daten zu verwerfen, eine Korrektur ist nicht möglich.


#### Eigenschaften biologischer Störungen
- Spektral alle Biosignale im selben Band (0...100Hz)
- Nichtlineare Verkopplung der Biosignale verhindern Trennung mit herkömmlichen Methoden
- Kein Biosignal deterministisch und reproduzierbar
- Transiente bzw apperiodische und instationäre Biosignale nicht qualifizierbar
- Eine Trennung kaum möglich, bestenfalls eine Reduktion (z.B. Abschwächung des EMG im EKG)

Das größte Problem bei der Reduktion von biologischen Störsignalen ist ihre funktionelle Verkopplung und physikalische Überlagerung im Volumenleiter Mensch. Die funktionelle Verkopplung (z.B. Einfluss der Atmung auf die Herzrate) ist nicht abschaltbar, ist nichtlinear und qualitativ unbekannt bzw. mit Methoden der BSA nicht beschreibbar. Außerdem sind die Verkopplungen in ihrer Komplexität weitgehend unerforscht und höchstens in Ansätzen dokumentiert.

Man kann im Einzelfall den Einfluss eines Biosignals auf ein anderes zum Teil reduzieren. So z.B. ist bekannt, dass das EMG ein breitbandiges und vor allem hochfrequentes Signals ist, während das EKG seine Hauptanteile eher im niederfrequenten Bereich besitzt. Daher kann man den Einfluss des EMG mit einem relativ einfachen Tiefpass reduzieren, allerdings auch auf Kosten der Beeinträchtigung des EKG.


## Medizinische Messverstärker
### Dynamik, Linearität
Messverstärker Anforderungen:
- Linearität im Arbeitsbereich
- Linearer Phasenfrequenzgang
- Geringes Eigenrauschen
- Hohe Gleichtaktunterdrückung
- Übersteuerungsfestigkeit

1. Mit Linearität im Arbeitsbereich ist die statische Linearität des Verstärkers gemeint, also die statische Beziehung zwischen der Ausgans-zu der Eingangsspannung $U_a/U_e$.
2. Mit linearem Phasengang ist die dynamische Linearität gemeint, also die Erhaltung der Signalform bei der Verstärkung. Beim nichtlinearen Phasengang wird die Veränderung der Signalform fälschlicherweise auch als ,,lineare Verzerrung'' bezeichnet, wohl in Anlehnung an die nichtlinearen Verzerrungen im Arbeitsbereich.
3. Das Eigenrauschen des Messverstärkers ist ein sehr wichtiger Parameter vor allem in der medizinischen Messtechnik, denn das Rauschen liegt im Bereich der zu messenden Signale im unteren Mikrovoltbereich. Ausgerechnet das 1/f-Halbleiterrauschen liegt dort, wo die Biosignale ihren wesentlichen Spektralanteil aufweisen.
4. Wie schon erwähnt, ein wesentlicher Teil der beherrschbaren technischen Störungen bilden die Gleichtaktsignale. Daher wird von den Messverstärkern eine hohe CMRR gefordert, die nicht unter 100dB liegen sollte.
5. Die Empfindlichkeit eines Verstärkers allein ist noch kein hinreichendes Kriterium. Ein medizinischer Verstärker muss übersteuerungsfest sein, damit er nicht schon beim ersten Defibrilationsimpuls oder bei der ersten OP mit HF-Gerät seine Dienste aufgibt. Und dies zu gewährleisten ist für die Elektroniker eine echte Herausforderung: Es gilt nämlich das Ziel, einen Verstärker aufzubauen, der im Mikrovoltbereich arbeitet, dennoch bei Spannungen von mehreren 100V (Defibrilation) oder HF-Leistungen (um 100W) nicht beschädigt wird und zeitnah seinen Arbeitsbereich wiederfindet.

![](Assets/Biosignalverarbeitung-Linearität-arbeitsbereich.png)

Die Pegel der Biosignale sind gut bekannt, so dass den Arbeitsbereich des Verstärkers vorzugeben, kein Problem darstellt. So wird dieser Bereich für das EKG etwa zwischen - 5 und +5 mV liegen. Als Reserve bis zur Begrenzung sollte man mindestens 50% des Arbeitsbereiches vorsehen.

### Eigenrauschen
![](Assets/Biosignalverarbeitung-eigenrauschen.png)

Das Halbleiterrauschen (1/f) erreicht bei etwa 10Hz den Pegel des weißen (Widerstands-) Rauschens. Da aber in diesem Bereich die meiste Energie der Biosignale liegt, ist es beim Schaltungsentwurf wichtiger, geeignete Halbleiter auszusuchen als sich auf die Minimierung des Widerstandsrauschens zu beschränken. Da die Auswahl an guten Halbleitern sehr begrenzt ist und dadurch den Entwicklern deutliche technologische Grenzen gesetzt sind, versuchen einige Konstrukteure und Hersteller die Eigenschaften ihrer Technik dadurch zu beschönigen, dass sie das Spektrum nach unten durch einen Hochpass begrenzen und erst dann die Rauschspannung messen und angeben. Daher muss man bei den Vergleichen verschiedener Techniken an dieser Stelle sehr vorsichtig vorgehen. Beispielsweise ist ein Verstärker, der angeblich nur 2uV Rauschspannung erzeugt aber erst bei 1Hz beginnt sicher nicht besser, als einer mit 3uV Rauschspannung dafür aber bereits ab 0.1Hz verstärkt.

### Frequenzgang
Linearer Phasenfrequenzgang: Keine Formverzerrung
- Gruppenlaufzeit: $d(f)=const.$
- Phasenfrequenzgang: $\phi(f)=\int 

Die wichtigste Eigenschaft der Biosignale, die von Medizinern diagnostisch genutzt wird, ist ihre Signalform. Daher lautet eine der grundlegenden Anforderungen an die Messtechnik und die BSA, dass die Signalform nicht verfälscht werden darf. Das bedeutet, dass sowohl im analogen als auch im digitalen Teil des Messsystems die Gruppenlaufzeit konstant sein muss. Daraus lässt sich die Forderung herleiten, dass der Phasengang linear sein muss, zumindest im Übertragungsbereich.

## Differenzverstärker
### Funktionsprinzip

### Differenz- und Gleichtaktverhalten

# Signalkonditionierung, Abtastung und Digitalisierung
# Digitale Filterung

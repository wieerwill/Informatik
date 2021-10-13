# Biosignalverarbeitung
## Sensorik
Im Normalfall werden Sensoren verwendet, die eine physikalische oder chemische Größe in ein elektrisches Signal umwandeln bzw. eine elektrische Größe beeinflussen, die weiter verarbeitet werden können. Eine Umwandlung der Energieform der Biosignale ist notwendig. Selbst bei Sensoren für elektrische Größen ist eine Umwandlung (von Ionenleitung zur Elektronenleitung) nötig.

Weitere Sensorengruppen, wie Temperatur-und chemische Sensoren werden hier nicht behandelt, da ihre Dynamik aus Sicht der BSA vernachlässigbar gering ist.

### Klassifikation von Sensoren
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

### Druck, Dehnung und Kraft
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

### Durchfluss, Volumen
### Optische Sensoren
### Akustische Sensoren

## Verstärkung und analoge Filterung
## Signalkonditionierung, Abtastung und Digitalisierung
## Digitale Filterung

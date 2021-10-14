# Einführung
Betriebssysteme stecken nicht nur in Einzelplatzrechnern, sondern z.B. auch in:
- Informationssystemen
  - Gesundheitswesen
  - Finanzdienstleister
- Verkehrsmanagement-Systemen
  - Eisenbahn
  - Flugwesen
- Kommunikationssystemen
  - Mobilfunk
  - Raumfahrt
- eingebettetenSystemen
  - Multimedia
  - Fahrzeugsysteme
  - Sensornetze
- ... $\rightarrow$ verschiedenste Anforderungen!

Konsequenz: Spezialbetriebssysteme für Anforderungen wie ...
- Robustheit
- Echtzeitfähigkeit
- Energieeffizienz
- Sicherheit
- Adaptivität
- ...

Gegenstand dieser Vorlesung: Konstruktionsrichtlinien für solche ,,High-End Betriebssysteme''

## Funktionale und nichtfunktionale Eigenschaften
- Beispiel: Autokauf ,,Mit unserem Fahrzeug können Sie einkaufen fahren!''
- Beispiel: Handykauf ,,Mit unserem Telefon können Sie Ihre Freunde und Familie anrufen!''

- Anforderungen (Requirements)
    - Funktionale und nichtfunktionale Eigenschaften (eines Produkts, z.B. Softwaresystems) entstehen durch Erfüllung von funktionalen und nichtfunktionalen Anforderungen
- funktionale Eigenschaft
    - legt fest, was ein Produkt tun soll.
    - Bsp Handykauf: Das Produkt soll Telefongespräche ermöglichen.
- eine nichtfunktionale Eigenschaft (NFE)
    - legt fest, wie es dies tun soll, also welche sonstigen Eigenschaften das Produkt haben soll.
    - Bsp Handykauf: Das Produkt soll klein, leicht, energiesparend, strahlungsarm, umweltfreundlich,... sein.
- andere Bezeichnungen nichtfunktionaler Eigenschaften
    - Qualitäten bzw. Qualitätsattribute (eines Software-Produkts):
        - Nichtfunktionale Anforderungen bzw. Eigenschaften eines Software-Systems bzw. -Produkts oft auch als seine Qualitäten bezeichnet.
        - einzelne realisierte Eigenschaft ist demzufolge ein Qualitätsattribut (quality property) dieses Systems bzw. Produkts.
    - Weitere in der Literatur zu findende Begriffe in diesem Zusammenhang:
        - Non-functionalrequirements/properties
        - Constraints
        - Quality ofservice(QoS) requirements
        - u.a.
- ,,~ilities''
    - im Englischen:nichtfunktionale Eigenschaften eines Systems etc. informell auch als seine „ilities“ bezeichnet, hergeleitet von Begriffen wie
        - Stability
        - Portability
        - ...
    - im Deutschen: ( ,,itäten'',,,barkeiten'', ... möglich aber sprachästhetisch fragenswert)
        - Portab-ilität , Skalier-barkeit, aber: Offen-heit , Performanz, ...

## Konsequenzen für Betriebssysteme
### Hardwarebasis
Einst: Einprozessor-Systeme

Heute:
- Mehrprozessor-Systeme
- hochparallele Systeme
- neue Synchronisationsmechanismen erforderlich
- $\rightarrow$ unterschiedliche Hardware und deren Multiplexing aufgrund unterschiedlicher nichtfunktionaler Eigenschaften

### Betriebssystemarchitektur
Einst: Monolithische und Makrokernel-Architekturen

Heute:
- Mikrokernel(-basierte) Architekturen
- Exokernelbasierte Architekturen ( Library-Betriebssysteme )
- Virtualisierungsarchitekturen
- Multikernel-Architekturen
- $\rightarrow$ unterschiedliche Architekturen aufgrund unterschiedlicher nichtfunktionaler Eigenschaften

### Ressourcenverwaltung
Einst: sog. Batch-Betriebssysteme: Stapelverarbeitung von Jobs (FIFO, Zeitgarantie: irgendwann)

Heute:
- Echtzeitgarantien für Multimedia und Safety-kritische Anwendungen (Unterhaltung, Luft-und Raumfahrt, autonomes Fahren)
- echtzeitfähige Scheduler, Hauptspeicherverwaltung, Ereignismanagement, Umgangmit Überlast und Prioritätsumkehr ...
- $\rightarrow$ unterschiedliche Ressourcenverwaltung aufgrund unterschiedlicher nichtfunktionaler Eigenschaften

### Betriebssystemabstraktionen
- zusätzliche Abstraktionen und deren Verwaltung ...
  - ... zur Reservierung von Ressourcen ($\rightarrow$ eingebettete Systeme)
  - ... zur Realisierung von QoS-Anforderungen ($\rightarrow$ Multimediasysteme)
  - ... zur Erhöhung der Ausfallsicherheit ($\rightarrow$ verfügbarkeitskritische Systeme)
  - ... zum Schutz vor Angriffen und Missbrauch ($\rightarrow$ sicherheitskritische Systeme)
  - ... zum flexiblen und modularen Anpassen des Betriebssystems ($\rightarrow$ hochadaptive Systeme)
- $\rightarrow$ höchst diverse Abstraktionen von Hardware aufgrund unterschiedlicher nichtfunktionaler Eigenschaften

### Betriebssysteme als Softwareprodukte
- Betriebssystem:
    - eine endliche Menge von Quellcode, indiziert durch Zeilennummern: MACOSX = $\{0, 1, 2, ..., 4399822, ...\}$
    - ein komplexes Softwareprodukt ...welches insbesondere allgemeinen Qualitätsanforderungen an den Lebenszyklusvon Softwareprodukten unterliegt!
- an jedes Softwareprodukt gibt es Anforderungen an seine Nutzung und Pflege $\rightarrow$ Evolutionseigenschaften
- diese können für Betriebssysteme höchst speziell sein (Korrektheitsverifikation, Wartung, Erweiterung, ...)
- $\rightarrow$ spezielle Anforderungen an das Softwareprodukt Betriebssystem aufgrund unterschiedlicher nichtfunktionaler Eigenschaften

## NFE von Betriebssystemen
Funktionale Eigenschaften (= Funktionen, Aufgaben) ... von Betriebssystemen:
- Betriebssysteme: sehr komplexe Softwareprodukte
- Ein Grund hierfür: besitzen Reihe von differenzierten Aufgaben - also funktionale Eigenschaften

Grundlegende funktionale Eigenschaften von Betriebssystemen:
1. **Hardware-Abstraktion** (Anwendungen/Programmierern eine angenehme Ablaufumgebung auf Basis der Hardware bereitstellen)
2. **Hardware-Multiplexing** (gemeinsame Ablaufumgebung zeitlich oder logisch getrennt einzelnen Anwendungen zuteilen)
3. **Hardware-Schutz** (gemeinsame Ablaufumgebung gegen Fehler und Manipulation durch Anwendungen schützen)

Nichtfunktionale Eigenschaften (Auswahl) von Betriebssystemen:
- Laufzeiteigenschaften
  - Sparsamkeit und Effizienz
  - Robustheit
  - Verfügbarkeit
  - Sicherheit (Security)
  - Echtzeitfähigkeit
  - Adaptivität
  - Performanz
- Evolutionseigenschaften
  - Wartbarkeit
  - Portierbarkeit
  - Offenheit
  - Erweiterbarkeit

Klassifizierung: Nichtfunktionale Eigenschaften unterteilbar in:
1. Laufzeiteigenschaften (execution qualities)
    - zur Laufzeit eines Systems beobachtbar
    - Beispiele: ,,security'' (Sicherheit), ,,usability'' (Benutzbarkeit), ,,performance''
    (Performanz), ...
2. Evolutionseigenschaften (evolution qualities)
    - charakterisieren (Weiter-) Entwicklung- und Betrieb eines Systems
    - Beispiele: ,,testability'' (Testbarkeit), ,,extensibility'' (Erweiterbarkeit) usw.
- liegen in statischer Struktur eines Softwaresystems begründet

## Inhalte der Vorlesung
Auswahl sehr häufiger NFE von Betriebssystemen:
- Sparsamkeit und Effizienz
- Robustheit
- Verfügbarkeit
- Sicherheit (Security)
- Echtzeitfähigkeit
- Adaptivität
- Performanz
  
Diskussion jeder Eigenschaft: (Bsp.: Echtzeitfähigkeit)
- Motivation, Anwendungsgebiete, Begriffsdefinition(en) (Bsp.: Multimedia- und eingebettete Systeme)
- Mechanismen und Abstraktionen des Betriebssystems (Bsp.: Fristen, Deadline-Scheduler)
- unterstützende Betriebssystem-Architekturkonzepte (Bsp.: Mikrokernel)
- ein typisches Beispiel-Betriebssystem (Bsp.: QNX)
- Literaturliste


# Sparsamkeit und Effizienz
# Robustheit und Verfügbarkeit
# Sicherheit
# Echtzeitfähigkeit
# Adaptivität
# Performanz und Parallelität
# Zusammenfassung


# Literatur

- NFE in Betriebssystemen
    - Eeles, Peter; Cripps, Peter: The Process of Software Architecting
- Funktionale Eigenschaften eines Betriebssystem
    - Tanebaum, Andrews; Bos, Herbert: Modern Operating Systems
    - Tanebaum, Andrews; Woodhull, Alberts: Operating Systems Design and Implementation
    - Stallings, William: Operating Systems: Internals and Design Principles
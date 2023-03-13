---
title: Telematik 1 
date: Sommersemester 2020
author: Felix Husslein, Robert Jeutter
---

- [Kapitel 1: Kurze Übersicht](#kapitel-1-kurze-übersicht)
  - [Unterschiede zwischen Telefon und Internet](#unterschiede-zwischen-telefon-und-internet)
  - [Verbindungsarten:](#verbindungsarten)
  - [Phyische Verbindungen (Arten)](#phyische-verbindungen-arten)
  - [Größere Netzwerke](#größere-netzwerke)
  - [Multiplexing](#multiplexing)
- [Kapitel 2: Architektur](#kapitel-2-architektur)
  - [Verbindungsorientiert vs. Verbindungslos](#verbindungsorientiert-vs-verbindungslos)
  - [Protokolle](#protokolle)
    - [Protokollspezikiationen:](#protokollspezikiationen)
    - [Layering: Vor- und Nachteile](#layering-vor--und-nachteile)
  - [ISO/OSI Referenzmodell](#isoosi-referenzmodell)
      - [Kritik am ISO/OSI Modell](#kritik-am-isoosi-modell)
      - [Architekturvoraussetzungen für das Internet](#architekturvoraussetzungen-für-das-internet)
      - [Grundlagen der Internetarchitektur](#grundlagen-der-internetarchitektur)
    - [TCP/IP Referenzmodell](#tcpip-referenzmodell)
      - [Kritik am TCP/IP Modell](#kritik-am-tcpip-modell)
    - [ISO/OSI vs TCP/IP](#isoosi-vs-tcpip)
  - [Standardisierung](#standardisierung)
    - [ISO Standardisierverfahren](#iso-standardisierverfahren)
  - [Zusammenfassung Kapitel 2](#zusammenfassung-kapitel-2)
- [Kapitel 3: Physikalisches Layer](#kapitel-3-physikalisches-layer)
  - [Synchronisation](#synchronisation)
    - [Vereinfachtes Konzept:](#vereinfachtes-konzept)
  - [Breitband- vs. Basisbandübertragung](#breitband--vs-basisbandübertragung)
    - [Breitbandübertragung](#breitbandübertragung)
  - [Digitales vs. Analoges Signal](#digitales-vs-analoges-signal)
  - [Zusammenfassung Kapitel 3](#zusammenfassung-kapitel-3)
- [Kapitel 4: Data Link Layer](#kapitel-4-data-link-layer)
  - [Services des Link Layers](#services-des-link-layers)
  - [Einfache Linklayerfunktionen (Übersicht)](#einfache-linklayerfunktionen-übersicht)
    - [Framing](#framing)
    - [Fehlerkontrolle](#fehlerkontrolle)
    - [Verbindungsaufbau](#verbindungsaufbau)
    - [Flusskontrolle](#flusskontrolle)
  - [Framing](#framing-1)
    - [Framing durch Zählen der Charakter](#framing-durch-zählen-der-charakter)
    - [Framing durch Flagbitmuster/Bitstuffing](#framing-durch-flagbitmusterbitstuffing)
    - [Framing durch Codeverletzungen](#framing-durch-codeverletzungen)
  - [Fehlerkontrolle - Redundanz](#fehlerkontrolle---redundanz)
    - [Parität](#parität)
    - [Checksummen](#checksummen)
    - [Hammingdistanz](#hammingdistanz)
    - [Frame Mengen - Code Books, Code](#frame-mengen---code-books-code)
    - [Cyclic Redundancy Check - CRC](#cyclic-redundancy-check---crc)
    - [Rückwärtsfehlerkontrolle](#rückwärtsfehlerkontrolle)
      - [Send and Wait](#send-and-wait)
        - [Alternating Bit Protokoll](#alternating-bit-protokoll)
        - [ARQ - Sliding Windows](#arq---sliding-windows)
          - [Übertragungsfehler und Empfangsfenstergröße](#übertragungsfehler-und-empfangsfenstergröße)
      - [Go-Back-N](#go-back-n)
        - [Selective Reject / Selective Repeat](#selective-reject--selective-repeat)
        - [Duplexoperation und Piggybacking](#duplexoperation-und-piggybacking)
      - [Leistungsverhalten:](#leistungsverhalten)
  - [Folgerung Kapitel 4](#folgerung-kapitel-4)
- [Kapitel 5: Medium Access Control (MAC)](#kapitel-5-medium-access-control-mac)
  - [Einführung: Multiple Access Link und Protokolle](#einführung-multiple-access-link-und-protokolle)
    - [Multiple Access Protokoll](#multiple-access-protokoll)
    - [Broadcastkanal mit Rate R b/s](#broadcastkanal-mit-rate-r-bs)
    - [Statisches Multiplexing](#statisches-multiplexing)
    - [Berstender Verkehr (Burst)](#berstender-verkehr-burst)
    - [Statisches multiplexing berstenden Verkehrs - Verzögerung](#statisches-multiplexing-berstenden-verkehrs---verzögerung)
    - [Dynamische Kanalzuweisung](#dynamische-kanalzuweisung)
      - [Annahmen für die dynmaische Kanalzuweisung](#annahmen-für-die-dynmaische-kanalzuweisung)
        - [Zahlen von Merit](#zahlen-von-merit)
          - [Durchsatz und angebotene Last](#durchsatz-und-angebotene-last)
    - [Grundlegende Optionen für MAC](#grundlegende-optionen-für-mac)
      - [Kollisionsbehaftete Protokolle](#kollisionsbehaftete-protokolle)
    - [Carrier Sensing](#carrier-sensing)
      - [CSMA und die Ausbreitungsverzögerung](#csma-und-die-ausbreitungsverzögerung)
      - [Collision Detetion - CSMA/CD](#collision-detetion---csmacd)
      - [Wahl einer zufälligen Wartezeit](#wahl-einer-zufälligen-wartezeit)
      - [Adaption von k an die Last](#adaption-von-k-an-die-last)
      - [Binary exponential Backoff](#binary-exponential-backoff)
    - [Wettbewerbsfreie Protokolle](#wettbewerbsfreie-protokolle)
    - [Polling und Tokenweitergabe](#polling-und-tokenweitergabe)
    - [Bit-Map-Protokoll](#bit-map-protokoll)
    - [Limited Contention Protokolle](#limited-contention-protokolle)
  - [Fallstudie Ethernet](#fallstudie-ethernet)
    - [Topologien](#topologien)
      - [Unzuverlässiger, verbindungsloser Dienst](#unzuverlässiger-verbindungsloser-dienst)
      - [Physisches Layer](#physisches-layer)
      - [Ethernet verwendet CSMA/CD](#ethernet-verwendet-csmacd)
        - [Ethernet - CSMA-CD Algorithmus](#ethernet---csma-cd-algorithmus)
      - [Effizienz](#effizienz)
      - [Hubs](#hubs)
      - [Switch](#switch)
      - [Geschwindigkeiten der Ethernetversionen](#geschwindigkeiten-der-ethernetversionen)
  - [Zusammenfassung Kapitel 5](#zusammenfassung-kapitel-5)
- [Kapitel 6 Internetworking](#kapitel-6-internetworking)
  - [LAN Verbindungen](#lan-verbindungen)
    - [Gründe für mehrere LANs](#gründe-für-mehrere-lans)
    - [Möglichkeiten des Überwindens der Begrenzungen](#möglichkeiten-des-überwindens-der-begrenzungen)
  - [Physical Layer Verbindungen](#physical-layer-verbindungen)
    - [Repeater](#repeater)
    - [Hub](#hub)
  - [Data Link Layer](#data-link-layer)
    - [Switch](#switch-1)
      - [Pfaderkennung - Selbstlernen](#pfaderkennung---selbstlernen)
      - [Weiterleiten](#weiterleiten)
    - [Bridges](#bridges)
      - [Rückwärtslernen in Bridges - Bootstrapping](#rückwärtslernen-in-bridges---bootstrapping)
        - [Lösung 1: Einschränken des Flutens](#lösung-1-einschränken-des-flutens)
        - [Lösung 2: Spanning Trees](#lösung-2-spanning-trees)
    - [Higher-Layer Verbindungen](#higher-layer-verbindungen)
      - [Router](#router)
      - [Gateways](#gateways)
    - [Weitere Probleme mit LAN/LAN Verbindungen](#weitere-probleme-mit-lanlan-verbindungen)
  - [Zusammenfassung Kapitel 6](#zusammenfassung-kapitel-6)
- [Kapitel 7: Netzwerklayer](#kapitel-7-netzwerklayer)
  - [Bauen großer Netzwerke](#bauen-großer-netzwerke)
  - [Netzwerklayerfunktionen](#netzwerklayerfunktionen)
    - [Weiterleitung](#weiterleitung)
    - [Durchsuchen der Routingtabelle](#durchsuchen-der-routingtabelle)
  - [Zusammenspiel zwischen Routing und Weiterleitung](#zusammenspiel-zwischen-routing-und-weiterleitung)
    - [Verbindungsaufbau](#verbindungsaufbau-1)
    - [Netzwerkservicemodell](#netzwerkservicemodell)
    - [Virtuelle Schaltkreisbasierte vs. Datagrammorientierte Netzwerke](#virtuelle-schaltkreisbasierte-vs-datagrammorientierte-netzwerke)
    - [Verbindungslose und Verbindungsbasierende Dienste auf dem Netzwerklayer](#verbindungslose-und-verbindungsbasierende-dienste-auf-dem-netzwerklayer)
    - [Virtuelle Schaltkreise](#virtuelle-schaltkreise)
    - [Implementierung virtueller Schaltkreise](#implementierung-virtueller-schaltkreise)
    - [Weiterleitungstabellen](#weiterleitungstabellen)
    - [VC Signalprotokolle](#vc-signalprotokolle)
    - [Datagrammnetzwerke](#datagrammnetzwerke)
    - [Longest Prefix Matching](#longest-prefix-matching)
    - [Datagramm vs. VC-Netzwerk](#datagramm-vs-vc-netzwerk)
  - [Wie ist ein Router eigentlich aufgebaut?](#wie-ist-ein-router-eigentlich-aufgebaut)
    - [Eingangsportfunktionen](#eingangsportfunktionen)
    - [Switching Fabric](#switching-fabric)
    - [Ausgangsports](#ausgangsports)
    - [Ausgangsportwarteschlangen](#ausgangsportwarteschlangen)
    - [Eingangsportwarteschlangen](#eingangsportwarteschlangen)
  - [IP - Datagrammformat und Paketverarbeitung](#ip---datagrammformat-und-paketverarbeitung)
    - [IP Paketformat](#ip-paketformat)
    - [IP Fragmentierung und Reassemblierung](#ip-fragmentierung-und-reassemblierung)
    - [IP Adressierung](#ip-adressierung)
      - [Scheitern von einfachen Adressierungsmethoden](#scheitern-von-einfachen-adressierungsmethoden)
      - [Adressierung und hierarchisches Routing](#adressierung-und-hierarchisches-routing)
      - [Nähe](#nähe)
      - [internetnamen und Adressen](#internetnamen-und-adressen)
      - [Klassen von IP-Adressen](#klassen-von-ip-adressen)
    - [IP-Adressierung](#ip-adressierung-1)
      - [Subnets](#subnets)
      - [IP Adressen](#ip-adressen)
      - [CIDR: Classless Inter Domain Routing](#cidr-classless-inter-domain-routing)
      - [Wie bekommt man eigentlich eine IP-Adresse?](#wie-bekommt-man-eigentlich-eine-ip-adresse)
      - [Wie kommt das Netzwerk eigentlich an seinen Subnetpart von IP-Adressen?](#wie-kommt-das-netzwerk-eigentlich-an-seinen-subnetpart-von-ip-adressen)
    - [IP Adressierung: Allokation von Adressen](#ip-adressierung-allokation-von-adressen)
      - [NAT - Network Address Translation](#nat---network-address-translation)
      - [Schließen der letzten Lücke: ARP](#schließen-der-letzten-lücke-arp)
        - [ARP Protokoll im gleichen LAN](#arp-protokoll-im-gleichen-lan)
        - [Routing in ein anderes LAN](#routing-in-ein-anderes-lan)
  - [ICMP und IPv6](#icmp-und-ipv6)
    - [ICMP: Internet Control Message Protocol](#icmp-internet-control-message-protocol)
      - [Traceroute und ICMP](#traceroute-und-icmp)
  - [IPv6](#ipv6)
    - [IPv6 Header](#ipv6-header)
    - [Weitere Veränderungen zu IPv4](#weitere-veränderungen-zu-ipv4)
    - [Übergang von IPv4 zu IPv6](#übergang-von-ipv4-zu-ipv6)
  - [Routing Algorithmen](#routing-algorithmen)
    - [Überblick über Routingalgorithmen](#überblick-über-routingalgorithmen)
    - [Fluten](#fluten)
      - [Mögliche Anwendungsfelder fürs Fluten](#mögliche-anwendungsfelder-fürs-fluten)
    - [Zufallsrouting](#zufallsrouting)
    - [Adaptive Routingalgorithmen](#adaptive-routingalgorithmen)
      - [Zentralisiertes adaptives Routing](#zentralisiertes-adaptives-routing)
      - [Isoliertes adaptives Routing](#isoliertes-adaptives-routing)
        - [Rückwärtslernen](#rückwärtslernen)
      - [Verteiltes adaptives Routing](#verteiltes-adaptives-routing)
      - [Klassifikation von Algorithmen für dezentralisiertes adaptives Routing](#klassifikation-von-algorithmen-für-dezentralisiertes-adaptives-routing)
    - [Distanzvektorrouting Algorithmen](#distanzvektorrouting-algorithmen)
      - [Distanzvektorrouting - Übersicht](#distanzvektorrouting---übersicht)
      - [Distanzvektoralgorithmus - Quelltext](#distanzvektoralgorithmus---quelltext)
      - [Distanzvektor: Reaktion auf Veränderung der Linkkosten](#distanzvektor-reaktion-auf-veränderung-der-linkkosten)
      - [Poisoned Reverse](#poisoned-reverse)
    - [Link State Routing](#link-state-routing)
      - [Dijkstrasalgorithmus zur Berechnung kürzester Pfade](#dijkstrasalgorithmus-zur-berechnung-kürzester-pfade)
      - [Weiterführende Diskussion zu Dijkstras Algorithmus](#weiterführende-diskussion-zu-dijkstras-algorithmus)
      - [Link State Routing mit Dijkstras Algorithmus](#link-state-routing-mit-dijkstras-algorithmus)
      - [Vergleich zwischen Link-State und Distanzvektoralgorithmen](#vergleich-zwischen-link-state-und-distanzvektoralgorithmen)
    - [Hierarchisches Routing](#hierarchisches-routing)
      - [Autonome Systeme](#autonome-systeme)
      - [Routing im Internet](#routing-im-internet)
      - [Verschiedenes Intra-AS und Inter-AS Routing, aber warum?](#verschiedenes-intra-as-und-inter-as-routing-aber-warum)
      - [Verbundene autonome Systeme](#verbundene-autonome-systeme)
      - [Inter-AS Aufgaben](#inter-as-aufgaben)
        - [Beispiel: Setzen der Weiterleitungstabelle in Router 1d](#beispiel-setzen-der-weiterleitungstabelle-in-router-1d)
        - [Beispiel: Wählen aus mehreren ASen](#beispiel-wählen-aus-mehreren-asen)
    - [Routing im Internet](#routing-im-internet-1)
      - [Intra-AS Routing (IGP)](#intra-as-routing-igp)
      - [RIP - Routing Information Protokoll](#rip---routing-information-protokoll)
      - [RIP - Advertisements](#rip---advertisements)
      - [RIP - Linkausfall und Linkrecovery](#rip---linkausfall-und-linkrecovery)
      - [RIP - Tabellenverarbeitung](#rip---tabellenverarbeitung)
    - [OSPF - Open Shortest Path First](#ospf---open-shortest-path-first)
      - [Weiterführende Funktionen](#weiterführende-funktionen)
      - [Hierarchisches OSPF](#hierarchisches-ospf)
      - [BGP - Border Gateway Protokoll](#bgp---border-gateway-protokoll)
      - [BGP - Grundlagen](#bgp---grundlagen)
      - [Verteilung von Erreichbarkeitsinformationen](#verteilung-von-erreichbarkeitsinformationen)
      - [Pfadattribute und BGP Routen](#pfadattribute-und-bgp-routen)
      - [BGP Routenwahl](#bgp-routenwahl)
      - [BGP Nachrichten](#bgp-nachrichten)
  - [Zusammenfassung Kapitel 7](#zusammenfassung-kapitel-7)
- [Kapitel 8: Transport Layer](#kapitel-8-transport-layer)
  - [Transportlayerdienste und Protokolle](#transportlayerdienste-und-protokolle)
  - [Transport vs. Netzwerklayer](#transport-vs-netzwerklayer)
  - [Transportlayerprotokolle im Internet](#transportlayerprotokolle-im-internet)
  - [Adressierung und Multiplexing](#adressierung-und-multiplexing)
  - [Multiplexing und Demultiplexing](#multiplexing-und-demultiplexing)
    - [Wie funktioniert Demultiplexing?](#wie-funktioniert-demultiplexing)
    - [Verbindungsloses Demultiplexing](#verbindungsloses-demultiplexing)
    - [Verbindungsorierntiertes Demultiplexing](#verbindungsorierntiertes-demultiplexing)
    - [Multithreaded-Webserver](#multithreaded-webserver)
    - [Verbindungskontrolle](#verbindungskontrolle)
      - [Aufbau der Transportverbindung](#aufbau-der-transportverbindung)
      - [Datentransferdienst](#datentransferdienst)
      - [Verbindungsabbau](#verbindungsabbau)
      - [Probleme während des Verbindungsaufbaus](#probleme-während-des-verbindungsaufbaus)
        - [Drei Wege Handshake](#drei-wege-handshake)
        - [Verbindungsablehnung](#verbindungsablehnung)
        - [Verbindungsabbbau](#verbindungsabbbau)
        - [Verbindungsabbau in der Realität](#verbindungsabbau-in-der-realität)
    - [Flusskontrolle](#flusskontrolle-1)
      - [Motivation: Kontrolle von Überlastsituationen](#motivation-kontrolle-von-überlastsituationen)
      - [Flaschenhälse auf der Empfängerseite](#flaschenhälse-auf-der-empfängerseite)
      - [Flusskontrolle](#flusskontrolle-2)
      - [Flusskontrolle - Pufferallokation](#flusskontrolle---pufferallokation)
      - [Flusskontrolle durch Continue und Stop](#flusskontrolle-durch-continue-und-stop)
      - [Implizite Flusskontrolle](#implizite-flusskontrolle)
      - [Kreditbasierte Flusskontrolle](#kreditbasierte-flusskontrolle)
      - [Flusskontrolle - Permits und Acknowledgements](#flusskontrolle---permits-und-acknowledgements)
    - [Staukontrolle](#staukontrolle)
      - [Warum benötigt man Staukontrolle?](#warum-benötigt-man-staukontrolle)
      - [Gründe für Stau](#gründe-für-stau)
      - [Zusammenfassung](#zusammenfassung)
      - [Adaptiere die Senderate an die Netzwerkkapazität](#adaptiere-die-senderate-an-die-netzwerkkapazität)
      - [Wünschenswerte Eigenschaften von Staukontrolle](#wünschenswerte-eigenschaften-von-staukontrolle)
      - [Designoptionen für Staukontrollmechanismen](#designoptionen-für-staukontrollmechanismen)
      - [Mögliche Aktionen](#mögliche-aktionen)
      - [Mögliche Aktionen - Taxonomie](#mögliche-aktionen---taxonomie)
      - [Routeraktionen - Verwerfen von Paketen](#routeraktionen---verwerfen-von-paketen)
      - [Verwerfen von Paketen - Implizites Feedback](#verwerfen-von-paketen---implizites-feedback)
      - [Vermeiden von vollen Warteschlangen - Proaktive Aktionen](#vermeiden-von-vollen-warteschlangen---proaktive-aktionen)
      - [Choke Pakete](#choke-pakete)
      - [Warnungsbits](#warnungsbits)
      - [Random Early Detection](#random-early-detection)
      - [Was passiert aber, wenn Feedback empfangen wurde?](#was-passiert-aber-wenn-feedback-empfangen-wurde)
    - [Transportprotokolle im Internet](#transportprotokolle-im-internet)
      - [UDP - User Datagram Protocol](#udp---user-datagram-protocol)
        - [UDP Checksummen](#udp-checksummen)
      - [TCP - Transmission Control Protocol](#tcp---transmission-control-protocol)
        - [TCP - Sequenznummern und ACKs](#tcp---sequenznummern-und-acks)
        - [TCP Round Trip Time und Timeouts](#tcp-round-trip-time-und-timeouts)
        - [TCP Verbindungsaufbau](#tcp-verbindungsaufbau)
        - [Verbindungsidentifikation bei TCP](#verbindungsidentifikation-bei-tcp)
        - [TCP Verbindungsmanagement](#tcp-verbindungsmanagement)
        - [TCP Verbindung in drei Phasen](#tcp-verbindung-in-drei-phasen)
        - [Zuverlässiger Datentransfer in TCP](#zuverlässiger-datentransfer-in-tcp)
        - [TCP Senderevents](#tcp-senderevents)
        - [TCP Sender (vereinfacht)](#tcp-sender-vereinfacht)
        - [TCP ACK Generierung](#tcp-ack-generierung)
        - [Schnelle Neuübertragung](#schnelle-neuübertragung)
        - [Algorithmus](#algorithmus)
    - [TCP Fluss- und Staukontrolle](#tcp-fluss--und-staukontrolle)
      - [Sende- und Empfangspuffer bei TCP](#sende--und-empfangspuffer-bei-tcp)
      - [TCP Flusskontrolle: Angebotenes Fenster](#tcp-flusskontrolle-angebotenes-fenster)
      - [Nagles Algorithmus - Selbsttaktung und Fenster](#nagles-algorithmus---selbsttaktung-und-fenster)
      - [Staukontrolle bei TCP](#staukontrolle-bei-tcp)
        - [TCP ACK/Selbsttaktung](#tcp-ackselbsttaktung)
        - [Gute und schlechte Nachrichten](#gute-und-schlechte-nachrichten)
        - [Verkleinern des Staufensters](#verkleinern-des-staufensters)
        - [Vergrößern des Staufensters](#vergrößern-des-staufensters)
        - [Additives Erhöhen](#additives-erhöhen)
        - [AIMD - Sägezahnmuster der angebotenen TCP Last](#aimd---sägezahnmuster-der-angebotenen-tcp-last)
        - [Schnelle initialisierung - Slow Start (historischer Name)](#schnelle-initialisierung---slow-start-historischer-name)
        - [Verlassen des Slowstarts](#verlassen-des-slowstarts)
        - [Problematik der Paketbursts](#problematik-der-paketbursts)
          - [Lösung: Auch hier Slow Start verwenden](#lösung-auch-hier-slow-start-verwenden)
      - [Zusammenfassung TCP Staukontrolle](#zusammenfassung-tcp-staukontrolle)
      - [TCP Performance](#tcp-performance)
        - [TCP Durchsatz](#tcp-durchsatz)
        - [TCP Fairness](#tcp-fairness)
      - [Fairness](#fairness)
          - [Fairness und UDP](#fairness-und-udp)
          - [Fariness und parallele TCP-Verbindungen](#fariness-und-parallele-tcp-verbindungen)
          - [Verzögerungsmodellierung](#verzögerungsmodellierung)
          - [Festes Staufenster](#festes-staufenster)
          - [TCP Verzögerungsmodellierung: Slow Start](#tcp-verzögerungsmodellierung-slow-start)
    - [Fallstudie HTTP Modellierung](#fallstudie-http-modellierung)
      - [HTTP Antwortzeiten](#http-antwortzeiten)
  - [Zusammenfassung Kapitel 8](#zusammenfassung-kapitel-8)
- [Kapitel 9: Internet Application Layer](#kapitel-9-internet-application-layer)
  - [Erstellen einer Netzwerkanwendung](#erstellen-einer-netzwerkanwendung)
  - [Prinzipien von Netzwerkanwendungen: Architekturen](#prinzipien-von-netzwerkanwendungen-architekturen)
    - [Client-Server Architektur](#client-server-architektur)
    - [Peer-to-Peer Architketur](#peer-to-peer-architketur)
    - [Hybride Client-Server und P2P](#hybride-client-server-und-p2p)
  - [Prozesskommunikation](#prozesskommunikation)
    - [Sockets](#sockets)
    - [Adressierung von Prozessen](#adressierung-von-prozessen)
  - [Durch das Anwendungsprotokoll festgelegte Eigenschaften](#durch-das-anwendungsprotokoll-festgelegte-eigenschaften)
    - [Welche Transportdienste werden von den Anwendungen benötigt?](#welche-transportdienste-werden-von-den-anwendungen-benötigt)
  - [Internettransportprotokolldienste](#internettransportprotokolldienste)
  - [Web & HTTP](#web--http)
    - [HTTP Übersicht](#http-übersicht)
    - [HTTP Verbindungen](#http-verbindungen)
    - [Antwortzeitmodellierung](#antwortzeitmodellierung)
    - [Persistentes HTTP](#persistentes-http)
    - [HTTP Anfragenachrichten](#http-anfragenachrichten)
    - [Hochladen von Einfaben](#hochladen-von-einfaben)
    - [Methodentypen](#methodentypen)
    - [HTTP Statuscodes](#http-statuscodes)
    - [HTTP Webcaching und Cookies](#http-webcaching-und-cookies)
      - [Nutzer-Server-Zustand: Cookies](#nutzer-server-zustand-cookies)
      - [Webcaches (Proxyserver)](#webcaches-proxyserver)
        - [Weitere Informationen über Webcaches](#weitere-informationen-über-webcaches)
        - [Bedingtes GET](#bedingtes-get)
    - [Webserverarchitekturen](#webserverarchitekturen)
      - [Grundlegende Webserveraufgaben](#grundlegende-webserveraufgaben)
      - [Webserverarchitekturen](#webserverarchitekturen-1)
        - [1. Prozessmodell](#1-prozessmodell)
        - [2. Threadmodell](#2-threadmodell)
        - [3. In-Kernel Modell](#3-in-kernel-modell)
        - [4. Eventbasiertes Modell](#4-eventbasiertes-modell)
      - [Performancevergleich](#performancevergleich)
          - [Webservercluster](#webservercluster)
      - [FTP: Das Dateitransferprotokoll](#ftp-das-dateitransferprotokoll)
        - [Separate Kontroll- & Datenverbindung](#separate-kontroll---datenverbindung)
        - [FTP Kommandos und Antworten](#ftp-kommandos-und-antworten)
      - [Electronic Mail: E-Mail](#electronic-mail-e-mail)
        - [SMTP](#smtp)
          - [SMTP Vergleich mit HTTP](#smtp-vergleich-mit-http)
        - [Mailnachrichtenformat](#mailnachrichtenformat)
          - [Nachrichtenformat: Multimediaerweiterungen](#nachrichtenformat-multimediaerweiterungen)
        - [Mailzugriffsprotokolle](#mailzugriffsprotokolle)
        - [POP3](#pop3)
        - [POP3 und IMAP](#pop3-und-imap)
    - [DNS - Domain Name System](#dns---domain-name-system)
      - [Verteilte hierarchische Datenbank](#verteilte-hierarchische-datenbank)
      - [DNS: Root Name Server](#dns-root-name-server)
      - [TLD, Authorative und lokale DNS Server](#tld-authorative-und-lokale-dns-server)
        - [Iterative Anfragen](#iterative-anfragen)
        - [Rekursive Anfragen](#rekursive-anfragen)
      - [DNS Caching und Updaten von Records](#dns-caching-und-updaten-von-records)
      - [DNS Records](#dns-records)
      - [DNS Protokoll, Nachrichten](#dns-protokoll-nachrichten)
        - [Einfügen von Records ins DNS](#einfügen-von-records-ins-dns)
    - [P2P Filesharing](#p2p-filesharing)
      - [Probleme mit einem zentralisierten Verzeichnis](#probleme-mit-einem-zentralisierten-verzeichnis)
      - [Anfragefluten: Gnutella](#anfragefluten-gnutella)
        - [Gnutella Protokoll](#gnutella-protokoll)
        - [Gnutella Peerjoining](#gnutella-peerjoining)
    - [Socketprogrammierung mit TCP](#socketprogrammierung-mit-tcp)
      - [Socketprogrammierung unter Verwendung von TCP](#socketprogrammierung-unter-verwendung-von-tcp)
      - [Stream Jargon](#stream-jargon)
    - [Socketprogrammierung mit UDP](#socketprogrammierung-mit-udp)
    - [Bauen eines einfachen Webservers](#bauen-eines-einfachen-webservers)
  - [Zusammenfassung Kapitel 9](#zusammenfassung-kapitel-9)
- [Kapitel 10: Netzwerk Sicherheit](#kapitel-10-netzwerk-sicherheit)
  - [Einführung - Bedrohungen, Sicherheitsziele, Schutzmaßnahmen](#einführung---bedrohungen-sicherheitsziele-schutzmaßnahmen)
    - [Was ist eine Bedrohung in einem Kommunikationsnetzwerk?](#was-ist-eine-bedrohung-in-einem-kommunikationsnetzwerk)
      - [Sicherheitsziele (Security Objectives) in Abnhängigkeit von der Anwendungsumgebung](#sicherheitsziele-security-objectives-in-abnhängigkeit-von-der-anwendungsumgebung)
      - [Sicherheitsziele technisch definiert](#sicherheitsziele-technisch-definiert)
      - [Bedrohungen technisch definiert](#bedrohungen-technisch-definiert)
      - [Sicherheitsanalyse von gelayerten Protokollarchitekturen](#sicherheitsanalyse-von-gelayerten-protokollarchitekturen)
        - [Angriff auf dem Nachrichtenlevel](#angriff-auf-dem-nachrichtenlevel)
        - [Sicherheitsmechanismen gegen Bedrohungen](#sicherheitsmechanismen-gegen-bedrohungen)
  - [Grundlagen der Sicherheitstechnologie](#grundlagen-der-sicherheitstechnologie)
    - [Terminologie](#terminologie)
    - [Sicherheitsdienste - Übersicht](#sicherheitsdienste---übersicht)
    - [Kryptologie - Definition und Terminologie](#kryptologie---definition-und-terminologie)
      - [Kryptographische Algorithmen](#kryptographische-algorithmen)
      - [Wichtige Eigenschaften von Verschlüsselungsalgorithmen](#wichtige-eigenschaften-von-verschlüsselungsalgorithmen)
        - [Symmetrische Verschlüsselung](#symmetrische-verschlüsselung)
        - [Asymmetrische Kryptographie](#asymmetrische-kryptographie)
        - [Erkennung verschlüsselter Nachrichten](#erkennung-verschlüsselter-nachrichten)
        - [Kryptographisches Protokoll](#kryptographisches-protokoll)
  - [Einführung in die Sicherheitsdienste von Kommunikationsnetzwerken](#einführung-in-die-sicherheitsdienste-von-kommunikationsnetzwerken)
    - [Sicherheit in Netzwerken: Was sollen wir wo tun?](#sicherheit-in-netzwerken-was-sollen-wir-wo-tun)
    - [Pragmatisches Modelll für sicheres und vernetztes Rechnen](#pragmatisches-modelll-für-sicheres-und-vernetztes-rechnen)
    - [Beziehungen zwischen Layern und Anforderungsleveln](#beziehungen-zwischen-layern-und-anforderungsleveln)
    - [Die IP Sicherheitsarchitektur IPSec](#die-ip-sicherheitsarchitektur-ipsec)
      - [Sicherheitsprobleme des Internetprotokolls](#sicherheitsprobleme-des-internetprotokolls)
      - [Sicherheitsziele von IPSec](#sicherheitsziele-von-ipsec)
      - [IPSec: Sicherheitsassoziation](#ipsec-sicherheitsassoziation)
      - [IPSec Protokollmodi](#ipsec-protokollmodi)
      - [IPSec: Verschachtelung von Sicherheitsassoziationen](#ipsec-verschachtelung-von-sicherheitsassoziationen)
        - [IPSec Authentication Header (AH)](#ipsec-authentication-header-ah)
        - [IPSec Encapsulating Security Protocol (ESP)](#ipsec-encapsulating-security-protocol-esp)
      - [IPSec: Etablierung von Sicherheitassoziationen](#ipsec-etablierung-von-sicherheitassoziationen)
  - [Internetfirewalls](#internetfirewalls)
    - [Terminologie](#terminologie-1)
    - [Firewallarchitekturen](#firewallarchitekturen)
      - [Einfache Paketfilterarchitektur](#einfache-paketfilterarchitektur)
      - [Die Screened Host Architektur](#die-screened-host-architektur)
      - [Die Screened Subnet Architektur](#die-screened-subnet-architektur)
      - [Firewalls: Paketfiltrierung](#firewalls-paketfiltrierung)

---
# Kapitel 1: Kurze Übersicht

## Unterschiede zwischen Telefon und Internet
- Telefon: Kontinuierliche Übertragung der Daten in beide Richtungen in nahezu Echtzeit
- Internet: Daten werden übertragen, Latenzen sind verschmerzbar

## Verbindungsarten:
Jede Verbindung benötigt eine Stelle welche von Bits in Signale wandelt und umgekehrt
> Signale sind die physische Repräsentation von Daten in der Form einer charakteristischen Variation in Zeit oder Ausbreitung…

Wichtige Eigenschaften auf niedrigem Niveau:
- Delay d: Zeit vom Versenden bis zum Empfangen
- Speed v: Wie schnell reist das Signal im Übertragungsmedium (Kupfer/Glasfaser bei 2/3c, WLAN bei c)

> delay = distance / v

## Phyische Verbindungen (Arten)
- Simplex: Nur ein Teilnehmer kann immer senden
- Half Duplex: Beide Seiten senden abwechselnd Daten über den selben Kanal
  - TDD (Time Division Duplex): Nutzer senden in einem festgelegten Zeitrahmen und kommen sich somit nicht in die Quere
- Full Duplex: Beide Nutzer können gleichzeitig senden
  - FDD (Frequenzy Division Duplex): Die Nutzer senden gleichzeitig auf unterschiedlichen Frequenzen. Somit ist ein Kabel für eine Verbindung in beide Richtungen ausreichend.
  - TDD (Time Division Duplex): Ist möglich, wenn einer sendet und der andere das zu Sendende kurz zwischenspeichert und später den Inhalt des Caches und das Aktuelle gleichzeitig sendet (Funktioniert nur, wenn das Medium doppelt so viel Kapazität wie die Datenrate des Senders hat)

## Größere Netzwerke
Einfaches untereinander Verbinden wird unübersichtlich, deshalb Einführung eines neuen Strukturelementes:
* Option 1: Circuit Switching
  * einfach
  * einmal aufgesetzt verbleiben die Ressourcen beim Nutzer
  * Circuit muss hergestellt werden, bevor kommuniziert werden kann
* Option 2: Packet Switching
  * Aufteilen von Daten in kleinere Pakete die nach und nach gesendet werden
  * Problem: Informationen zu Sender/Empfänger und Start/Endzeitpunkt eines Pakets müssen mit übermittelt werden
  * Switches übernehmen zusätzliche Aufgaben:
    * Zwischenspeichern in Puffern
    * Herausfinden des Ziels
    * Weiterleiten
  * Wird deshalb 'Store and Forward' Netzwerk genannt

## Multiplexing
Ähnlich, das Switch-Element hat aber nur eine ausgehende Leitung
1. TDM (Time Division Multiplexing): Übertrage ein Paket nach dem Anderen (Zeitliche Unterteilung)
2. FDM (Frequency Division Multiplexing): Gebrauch verschiedener Frequenzen um gleichzeitig Mehreres übertragen zu können.

Alternativen: CDM (Code DM), SPM (Space DM)

Sinn der Sache: Simuliert jedem Gerät seine eigene Datenleitung zu haben, ohne mehrere Leitungen bereitstellen zu müssen.

Ein Mux benötigt immer einen Demux, sodass das Paket den Weg korrekt verfolgen kann.

> Broadcast Medium:
>- Nur ein Sender zu jeder Zeit
>- Zugriffskontrolle (MUX o. Absprache)

Optionen für die Auswahl des nächsten Hops bei großen Netzwerken:
1. Fluten: Sende das Paket an alle Nachbarn
2. Hot Potato Routing: Sende an einen zufälligen Nachbarn
3. Routingtabellen: In jedem Switch mit einem Eintrag pro Ziel. Enthält Info über kürzeste Wege
   * Kriterien: Schleifenfreiheit, gute Einschätzungen
   * Konstruktion: Anfangs leer, wie soll ein Knoten etwas erfahren?
     * Passiv: Beobachtung des Traffics
     * Aktiv: Austausch von Informationen zwischen Routern
   * Problem: Ab gewisser Größe keine Speichermöglichkeit für jedes Ziel mehr
   * Lösung: Divide and Conquer: Aufteilen des Netzwerks in Ebenen

Fehlerquellen:
* Umwandlung von Bits in Signale
* Zugriff nicht möglich
* Paketverlust
* Fehlerhafte Routingtabellen
* Falsche Anordnung der Pakete
* Empfangsrate des Empfängers niedriger als die Senderate des Senders

Umgang mit Fehlern:
* Fehlerkontrolle := Zwischen Nachbarn oder Endpunkten
* Überlastungskontrolle 
  * Schutz gegen Pufferüberläufe, Regulierung der ins Netz geschickten Pakete (Staukontrolle)
  * Schutz von Endsystemen gegen zu viele ankommende Pakete (Flusskontrolle)
* Wo und Wie ist die wichtige Frage:
  * Im Endsystem oder im Netzwerk
  * Großer Unterschied zwischen Telefon und Internet

---
# Kapitel 2: Architektur
Netzwerke werden irgendwann zu groß, um sie als eine Ebene zu betrachten, deshalb: Aufspaltung in verschiedene Layer.
* Jedes Layer besitzt eigene Regeln und Prozeduren
* Jeder Dienst besitzt Schnittstellen zu höheren Ebenen
* Dienste können über ihren SAP (Service Access Point) erreicht werden und sind sozusagen ein Versprechen, was mit den Daten die am SAP ankommen passiert.

Services: Layer bieten ihren Nutzern über ihre Interfaces Dienste an.

Konvention für die Layer: Fortlaufende Nummerrierung, je höher desto abstrakter

Serviceprimitive: Menge an Operationen welche auf dem Interface eines Dienstes möglich sind

* Main Groups
  * Viele verschiedene Serviceprimitive sind denkbar, normalerweise werden vier verwendet:
    * Request (Req) := Anfrage an ein Layer einen Service auzuführen
    * Indication (Ind) := Ein Layer zeigt seinem Nutzer, dass etwas passiert ist (asynchrone Benachrichtigung)
    * Response (Res) := Ein Nutzer von höherem Layer beantwortet eine Indication
    * Confirmation (Conf) := Der ursprüngliche Dienstaufrufer wird über die Beendigung des Servicerequests informiert
  * Nicht alle Typen müssen immer zur Verfügung stehen
* Dateneinheiten
  * Dateneinheiten sind wohl begrenzte Nachrichten
    * Nur vollständige Nachrichten werden gesendet
    * Nur vollständige Nachrichten werden empfangen
  * Dateneinheit ist das einzelne Byte, eine Folge von Bytes oder ein Bytestream
    * Nicht in Nachrichten strukturiert
    * Sender sendet eine Folge, wovon der Empfänger jede Teilsequenz verwenden kann
* Korrektheitsanforderungen
  * Completeness: Alle gesendeten Nachrichten werden irgendwann zugestellt
  * Correctness: Alle Daten die ankommen, sind auch genau die, die losgeschickt wurden (unverändert, ohne Bitfehler)
  * Reihenfolgegetreu: Nachrichten und Bytesequenzen kommen in der korrekten Reihenfolge an
  * Verlässlich: Sicher, Verfügbar,…
  * Bestätigt: Erhalt von Daten wird dem Sender bestätigt

Nicht alle Anforderungen müssen immer erfüllt sein

## Verbindungsorientiert vs. Verbindungslos
* Telefonie vs. Post
  * Service mit Einrichtungsphase -> Verbindungsorientierter Dienst
    * Drei Phasen: Verbinden, Datenaustausch, Trennen
  * Aufruf eines Serviceprimitivs kann zu zu jeder Zeit stattfinden -> Verbindungsloser Dienst
  * Die Unterscheidung ist unabhängig von der Wahl von Circuit vs. Paketswitching
* Verbindungsorientierte Dienste müssen Primitive Bereitstellen um Verbindungen handhaben zu können:
  * CONNECT - Einrichtung der Verbindung
  * LISTEN - Warten auf Verbindungsanfragen
  * INCOMING_CONN - Anzeige eingehender Connectionrequests
  * ACCEPT - Annahme einer Verbindung
  * DISCONNECT - Terminierung einer Verbindung

Typische Servicebeispiele:
* Datagrammdienst:
  * Dateneinheit -> Nachrichten
  * Korrekt, aber nicht in Reihenfolge
  * Verbindungslos
  * unsicher/ nicht zuverlässig, nicht bestätigt
* Zuverlässiger Bytestream:
  * Dateneinheit -> Bytestrom
  * Korrekt, vollständig, reihenfolgegetreu, bestätigt
  * Manchmal sicher/zuverlässig
  * Verbindungsorientiert

## Protokolle
Was macht ein Protokoll aus? … spezielle Nachrichten werden versand, auf welche hin spezielle Taten unternommen werden
> Protokolle bestimmen das Format, die Reihenfolge von Nachrichten, welche über Netzwerkeinrichtungen versandt und empfangen werde, sowie Aktionen welche bei Übertragung und Erhalt von Nachrichten ausgeführt werden.

* Protokolle sind Regelsätze, welche beschreiben wie zwei oder mehr entfernte Teile (peers oder protocol entities) eines Layers kooperieren, um den Dienst des gegebenen Layers zu implementieren.
* Ein Protokoll ist die Implementierung eines Services

### Protokollspezikiationen:
* Das formale Verhalten eines Protokolls muss präzise spezifiziert werden
* Hierfür geeignet: FSMs (Finite State Machines)

Protokolle und FSMs
* FSMs implementieren die tatsächlichen Verhaltensregeln eines Protokolls
* Müssen mit entfernten Peers kommunizieren:
  * müssen hierfür den Service des darunterliegenden Layers verwenden
  * Mittels Serviceprimitiven, welche auch ankommende Daten an das Protokoll beretstellen können
  * Anzeigen von niedrigeren Layern in Events für die Protokollengine des höheren Levels

Wenn niedere Services verwendet werden, so werden den Nachrichten administrative Infos hinzugefügt, entweder als Header oder als Trailer
> Strict Layering:\
> Jedes Layer verwendet nur den Service des darunter liegenden Layers

Protokollmechanismen:
* Adressing
* Fragmentation
* Re-Sequencing
* Error-Control
* Flow-Control
* Congestation-Control
* Ressource-Allocation
* Multiplexing
* Compression
* Privacy, Authentication

Wie sollten Layer strukturiert werden?
* Modularisation vereinfacht die Wartung
* Layerstruktur und Protokolle definieren die Kommunikationsarchitektur

### Layering: Vor- und Nachteile
| Vorteile | Nachteile |
| -- | -- |
| Layer nötig um Komplexität zu verwalten und zu beherrschen | Layer können Funktionen redundant haben |
| Änderung der Implementierung eines Layerdienstes ist transparent | Verschiedene Layer können selbe Information benötigen |
| Typische Funktion: Ideales Netzwerk | Layer n benöitigt eventuell Einblick in Layern n+x |

Es existieren zwei Referenzmodelle:
* ISO/OSI
* TCP/IP

## ISO/OSI Referenzmodell
* Designprinzipien:
  * Ein Layer per Ebene
  * Jedes Layer mit wohldefinierter Funktion
  * Layergrenzen mit mglst. wenig Informationsfluss
  * Genug Layer zur Unterscheidung, wenig genug um Verwaltbarkeit zu schaffen

Insgesamt 7 Layer werden unterschieden.
* Physisches Layer (PH)
  * Bietet eine bittransparente Schnittstelle zum physischen Medium
  * Spezifiziert mechanische, elektrische, funktionale und prozedurale Mittel um die **physische Verbindung zwischen zwei offenen Systemen zu unterstützen.**
  * Physische Verbindung impliziert nicht die verbindungsorientierte Operation
  * Verschiedene Übertragungsmedien können genutzt werden, jeweils verschiedene Protokolle sind von Nöten
  * In-sequence Zustellung der Bits ist sichergestellt
  * Fehlererkennung ist manchmal inkludiert
* Link Layer (L)
  * Unterstützt Übertragung von service data units (SDU) größer als „word“ unter Systemen, welche über einen einzigen physischen Pfad verbunden sind.
  * Essentielle Funktion ist block synchronization
  * Teilweise wird Fehlererkennung oder Fehlerkontrolle zur Verfügung gestellt.
  * Im Fall von Halb-duplex oder multipoint links muss der Zugriff auf das Medium **kontrolliert werden und Peersysteme müssen addressiert werden.**
* Network Layer (N)
  * Erschafft einen logischen Pfad zwischen offenen Systemen, welche verbunden sind mit individuellen, möglicherweise verschiedenen Subnetworks
  * Dieser logische Pfad kann durch mehrere, möglicherweise verschiedene dazwischenliegende Subnetworks gehen
  * Diese Netzwerkebene unterstützt Routing, also müssen sich N-Service Benutzer nicht **um den Pfad kümmern**
  * Der N-Service ist uniform, unabhängig von der Variation an Subnetwork Technologien, Topologien, QoS und der Organisation
  * Netzwerk Addresse = Endsystem Addresse
* Transport Layer (T)
  * Vervollständigt den Übertragungsteil des OSI Stacks. Unterstützt die Übertragung mit **gefordertem QoS, auf wirtschaftliche Weise zwischen (T)-nutzern (normalerweise Prozessse in einem Endsystem), unabhängig von der Netzwerkstruktur**
  * Verschiedene Klassen von Protokollen mit verschiedenen Funktionalitäten sind **festgelegt (connectionoriented / connectionless; reliable / unreliable)**
* Session Layer (S)
  * Unterstützt die Synchronisation des Dialogs und die Verwaltung des Datenaustausches (möglicherweise über mehrere transport layer connections aufspannend)
  * Quarantine Data delivery - Eine ganze Gruppe von übertragenen S-SDUs wird zugestellt auf explizite Anfrage des Senders
  * Interaktionsverwaltung erlaubt ausdrücklich festzulegen, welcher S-User das Recht bekommt zu übertragen
  * Zurücksetzen der Verbindung auf vordefinierte Synchronisationspunkte
* Presentation Layer (P)
  * Unterstützt die Übersetzung von Daten und Datenstrukturen in einzigartige Repräsentation
  * Ausschließlich die Syntax wird modifiziert um die Semantik beizubehalten
  * Auswahl von einer der allgemein anerkannten Transfersyntax
  * Die lokale Syntax von jedem Endsystem wird in oder von der ausgewählten Transfer Syntax übersetzt
* Application Layer (A)
  * Unterstützt den direkten Endnutzer durch die Bereitstellung einer Vielzahl an application services
  * Dies kann sein:
  * Genereller Typ (z.B. Entfernte prozedurale Anrufe, Transaktionsdurchführung,...)
  * Spezifischer Typ (z.B. Virtuelles Terminal, Dateiübertragungszugriff und Verwaltung, Arbeitswechsel,...)
  * Ein typisches Beispiel: virtuelles Terminal (Funktionen des reellen Terminals werden in **virtuelle Funktionen gemappt**)

#### Kritik am ISO/OSI Modell
* Das Modell als solches mit der Unterteilung in Layer ist heutzutage sehr einflussreich
* Im praktischen Gebrauch aber eher irrelevant
* ISO konnte sich nicht durchsetzen
* Im Internetprotokoll (IP-Modell) wurden die obersten drei OSI-Layer in ein Applicationlayer zusammengefasst

#### Architekturvoraussetzungen für das Internet
* Generalität := Unterstütze alle möglichen Sets von Applikationen
* Heterogenität := Verbinde alle Arten von Netzwerktechnologien
* Robustheit := Wichtiger als Effizienz
* Erweiterbarkeit := Wichtiger als Effizienz
* Skalierbarkeit := Spätere Entdeckung

#### Grundlagen der Internetarchitektur
* Dumme Netzwerke, smarte Endgeräte
* Dumme Netzwerke brauchen nur einen geringsten gemeinsamen Dienst
  * Datagrammdienst: kein Verbindungsstatus in den Routern
  * Best effort: Gleichbehandlung
  * Verlieren, verdoppeln und vertauschen
* Intelligente Hosts
  * Behalten den Zustand
  * "Schicksalsteilung" - Wenn ein Host zusammenbricht und den Kommunikationszustand verliert, so teilen alle Applikationen, welche kommunizieren dieses Schicksal


### TCP/IP Referenzmodell
* Basierend auf dem ARPANET
* Definiert nur zwei Layer
  * Internetlayer: Packetswitching, Adressierung, Routing und Forwarding. Insbesondere für hierarchische Netze
  * Transportlayer
    * zuverlässiger Bytestrom: TCP (Transport Control Protokoll)
    * unzuverlässiges Datagramm: UDP (User Datagramm Protokoll)
* Niedere und höhere Layer nicht wirklich definiert
  * Host zu Host Kommunikation als gegeben angesehen
  * Anwendungen geschätzt
* Jedes Layer nimmt Daten vom darüberliegenden Layer, fügt eine Headereinheit hinzu und erstellt eine neue Dateneinheit und schickt diese an das Layer darunter
* TCP/IP - Reihe von Protokollen: viele anwendungsspezifische Protokolle über IP

#### Kritik am TCP/IP Modell
* keine klare Unterteilung zwischen Service, Protokoll und Interface
  * Gleichstellung von TCP mit zuverlässigem Bytestrom eigentlich nicht zulässig
  * Insbesondere unter IP
* Stark spezialisierter Stack, erlaubt keine Generalisierung
* Große Lücke unterhalb von IP
* Viele Einzelfalllösungen

### ISO/OSI vs TCP/IP
* ISO/OSI: Sehr nützliches Modell, keine existierenden Protokolle
* TCP/IP: Nicht existentes Modell, sehr nützliche Protokolle
* Deshalb: ISO/OSI Modell aber TCP/IP Stack

## Standardisierung
* Zum Bau großer Netzwerke werden Standards benötigt
* Traditionell aus dem Telekommunikationshintergrund
  * Eingelaufen, weltweit aber langsam
* Internet
  * Hauptsächlich um die IETF herum
  * Zählungsorientiert, Fokus auf funktionierenden Implementationen
  * Hoffnung auf schnelle Einführungszeiten
  * Herstellergremien

### ISO Standardisierverfahren
Standardisierungsprozess:
* DP: Draft Proposal
* DIS: Draft International Standard
* IS: International Standard

## Zusammenfassung Kapitel 2
* Komplexitätsbeherrschung nur mit Teilung in Subsysteme mit klar definierten Rollen -> Layering
* Jedes Layer bietet einen bestimmten Service an
  * Services werden mächtiger, je höher man in der Hierarchie aufsteigt
* Um einen Service anzubieten, muss ein Layer über entfernte Geräte verteilt sein
* Entfernte Teile eines Layers verwenden ein Protokoll um Zusammenzuarbeiten
  * Ein Protokoll ist eine horizontale, ein Service eine vertikale Beziehung
* Zwei wichtige Referenzmodelle existieren, welche beschreiben, wie man Funktionalitten in Layer gruppieren kann, welcher Service wo bereitgestellt wird, und wie man Protokolle strukturiert.

---
# Kapitel 3: Physikalisches Layer
## Synchronisation
Wann sollte man das Signal eigentlich sampeln?
* Wie weiß der Empfänger, wann das Signal auf einen Wert gemappt werden soll?
  * Konvention: In der Mitte jedes Symbols, nur wann ist das nun genau?
    * Länge ist typischerweise bekannt über die Konvention über die Symbolrate
* Der Empfänger muss mit dem Sender auf Bitlevel synchronisiert sein
  * Link-Layer zuständig für Framesynchronisation

### Vereinfachtes Konzept:
* Nimm an, dass Sender und Empfänger irgendwann synchron sind und beide eine Uhr haben, welche bei jedem Symbolschritt tickt
* Problem: Uhrendrift ist ein großes Problem - die Synchronisation wird verloren gehen
* Lösung:
  1. Stelle ein explizites Uhrensignal auf einem parallelen Kanal bereit
  2. Synchronisiere nur an kritischen Punkten (Uhrendrift ist nicht so schnell)
  3. Extrahiere Uhreninformation aus dem Signal selbst

Idee: Mit NRZL (Non-Return to Zero Level) müsste sich die Länge der Bits herausfinden lassen

Problem: Lange 1 oder 0 Folgen bieten keine Anhaltspunkte für die Bitgrenzen, somit hinfällig

Idee: Manchesterkodierung, stelle dem Sender bei jedem Bit Informationen bereit, dass dies eine Stelle ist, bei der ein Bit startet, stoppt, seine Mitte erreicht hat

Stellt eine ausreichende Anzahl an Signalwechseln sicher

Problem: Benötigen die doppelte Bandbreite, da die Baudrate = 2*Bitrate ist.

> Baudrate:\
> Die Baudrate beschreibt die Anzahl der Symbole welche innerhalb einer Zeiteinheit übertragen werden

## Breitband- vs. Basisbandübertragung
* Bisherige Übertragungsschemen: Basisbandübertragung
  * Schieben die digitalen Symbolsequenzen direkt auf den Draht
  * Verschiedene Level von Spannung/Stromstärke und co wird verwendet
* Probleme: Beschränkte Bandbreite verändert das Signal, Dämpfung und Verzerrung

### Breitbandübertragung
* Lösen vom breiten Spektrum für DC-Übertragung
* Verwende Sinuswelle als Träger, hat meist eine, allerdings auch nur eine, hohe Frequenz
* Reine Sinuswellen haben keine Information, deshalb Beeinflussung durch
  * Amplitude a
  * Frequenz f
  * Phase φ

Unterschiedliche Varianten der Signalmodulation möglich:
1. Amplitudenmodulation\
   Die Amplitude lässt sich beispielsweise als das zu sendende Signal s(t) geben. Spezialfälle:
   * s(t) analog - Amplitudenmodulation
   * s(t) digital - Amplitudenkeying
   * s(t) 0 oder 1 - An/Aus Keying
2. Frequenzmodulation
3. Phasenmodulation
   * Phasenmodulation mit hohen verschiedenen Werten pro Symbol
     * Der Empfänger kann gut zwischen Phasenwechseln unterscheiden
     * Verwende Phasenverschiebungen von 0, π/2, π, 3π/2 um je zwei Bits je Symbol zu kodieren
     * Besser noch in π/4 Schritten, somit Uhrenextraktion ermöglicht und Datenrate = 2* Symbolrate
     * Wird QPSK genannt
   * Verschiedene Modulationsarten können gut miteinander kombiniert werden
     * Beispiel: 16-QAM (Quadrature Amplitude Modulation)
     * Verwendet 16 Kombinationen von Phasenwechseln und Amplitude für jedes Symbol, somit Pro Symbol 2⁴ Bits codiert und übertragen

## Digitales vs. Analoges Signal
* Digitale Übertragung: Endliches Set von verschiedenen Signalen
* Analoge Übertragung: Unendliches Set von verschiedenen Signalen
* Beispiel: Signal korresponidert zur Stromstärke auf der Leitung
  * Digital: Endlich viele erlaubte Stromstärken, zb. 1A, 2A, 3A, 4A
  * Analog: Jede Stromstärke ist erlaubt
* Vorteil von digitaler Übertragung: Hohe Chance, dass der Empfänger, das gesendete Signal sehr gt rekonstruieren kann

Beispiele für Übertragungsmedien
* Geführte Übertragungsmedien
  * Kupferdrähte - Twisted Pair
  * Kupferdrähte - Koaxialkabel
  * Fibre Optics (Glasfaser)
* Drahtlose Übertragung
  * Radio
  * Mikrowellen
  * Infrarot
  * Lichtwellen

## Zusammenfassung Kapitel 3
* Das physikalische Layer ist zuständig für die Umwandlung einer logischen Sequenz an Bits in ein physisches Signal, welches sich durch den Raum ausbreiten kann
* Viele verschiedene Formen von physischen Signalen sind möglich
* Signale sind limitiert durch ihre Ausbreitung ineinem physikalischen Medium (begrenzte Bandbreite, …) und Rauschen.
* Bits können kombiniert werden in vielfach besetzte Symbole für die Übertragung
  * Erhöht die Differenz zwischen Baud- und Bitrate
  * Basisbandübertragung ist fehlerbehaftet, teilweise verbesserbar durch die Modulation eines Signals auf einen Träger (Breitbandübertragung)

---
# Kapitel 4: Data Link Layer
## Services des Link Layers
* Der Link Layer sitzt oberhalb des physischen Layers
  * Kann also einen Bitstromübertragungsdienst verwenden
  * Service kann allerdings inkorrekte Bits haben
* Erwartungen des höheren Netzwerklayers
  * Entweder Paketservice oder Bitstromdienst
  * Möchte von Fehlern nichts wissen und sich darum auch nicht kümmern

Optionen für Linklayer-Services
* Zuverlässig (Ja/Nein)
  * Zugestelltes Paket mit gleichem Inhalt wie das losgeschickte
  * Zustellung aller Pakete
  * Reihenfolgentreue
* Fehlerkontrolle verfügbar?
  * Vorwärts oder Rückwärtsorientiert
* Verbindungsorientiert?
  * Soll gemeinsamer Kontext etabliert werden
* Paket oder Bitstromabstraktion
  * Typischerweise in Computernetzwerken: Pakete
  * Gibt es eine maximale Paketlänge?

## Einfache Linklayerfunktionen (Übersicht)
### Framing
* Wie erstellt man aus dem Bitstrom des physischen Layers klar abgegrenzte Frames und wie erkennt man diese?
  * Für Fehlerkontrolle benötigt
  * Frames und Pakete sind das selbe, ist nur eine Namenskonvention für das Link Layer
* Zusätzlich: Fragmentation und Wiederzusammensetzung, falls Pakete des Netzwerklayers größer denen des Link Layers sein sollten

### Fehlerkontrolle
* Typischerweise eher im Netzwerklayer
* Fehlererkennung - gibt es fehlerhafte Bits?
* Fehlerkorrektur - Werden erkannte Fehler repariert?
  * Vorwärts - Investiere Arbeit bevor der Fehler passiert
  * Rückwärts - Investiere Arbeit nachdem der Fehler passiert ist, unternimm Reparaturversuche

### Verbindungsaufbau
* Verbindungen in vielerlei Hinsicht nützlich
  * Anwendungskontext
  * Fehlerkontrolle
* Frage: Wie baut man Verbindungen auf und wieder ab?
  * Insbesondere oberhalb von Frames, mittels virtueller Verbindungen, da es keine geswitchte Ende-zu-Ende Verbindung gibt

### Flusskontrolle
* Schneller Sender, langsamer Empfänger -> Puffer des Empfängers werden schneller gefüllt, als er diese leeren kann -> Verlorener Übertragungsaufwand
* Deshalb Adaptierung der Anzahl an Frames pro Link Layer Sendungen pro Zeit an den Empfänger

## Framing
* Wie kann man einen Bitstrom in eine Sequenz von Frames umwandeln?

### Framing durch Zählen der Charakter
* Idee: Veröffentlichen der Anzahl an Bits in einem Frame an den Empfänger
  * Hinzufügen der Infos in den Frameheader
* Problem: Fehlerhafte Zählerinformation zerstört wiederum die gesamte Framesynchronisation

### Framing durch Flagbitmuster/Bitstuffing
* Verwende ein Bitmuster welches Start/Ende markiert
* Verwende Bitstuffing, wann immer 5*1 hintereinander, so füge eine 0 daran an, außer beim Flagmuster
* Der Empfänger wiederum, wirft dann alle 0en nach 5*1 weg

### Framing durch Codeverletzungen
* Angenommen, die Codierungsregeln des physischen Layers lassen noch Spielraum
  * nicht alle Möglichkeiten an Kombinationen sind genutzt
  * Bei Manchester z.B. nur low/high und high/low
* Falls diese Regeln verletzt werden, können zusätzliche Daten übertragen werden, z.B. Beginn und Ende eines Frames
* Bei Manchester dann high/high oder low/low
* Zerstört zwar das Selbstclocking Feature aber bei kurzen Übertragungen verschmerzbar

## Fehlerkontrolle - Redundanz
* Zwei grundlegende Aspekte:
  * Erkennen
  * Korrigieren
* Beides ist unabhängig voneinander möglich
  * Erkennen ohne Korrigieren: Tu einfach so als wäre das Paket nie angekommen
  * Korrigiere aber erkenne nicht: Versuche so viel wie möglich zu korrigieren, aber versuche keine neuen zu entdecken und kümmere dich auch nicht darum
    * Beispiel: Videoanruf oder Musikstreaming, dort sind kleinere Bitfehler voll verschmerzbar
  > EDC = Error Detection and Correction Bits\
  > D = Data protected by error checking
* Fehlerdetektion ist nie 100% möglich: Fehler können übersehen werden …
* Irgendeine Form von Fehlerkontrolle erfordert Redundanz in den Frames
* Ohne Redundanz:
  * Frame der Länge m kann 2^m Frames darstellen
  * alle davon sind legal
  * Unmöglich hier Veränderungen zu erkennen
* Kernidee: Deklariere einige Nachrichten als illegal
  * Benötigen dennoch 2^m legale Frames, deshalb Frames mit n > m Gesamtlänge
  * Die extra Bits werden in Headern oder Trailern mit versand und erlauben es dem Empfänger illegale Frames zu erkennen
* Wie hilft das bei der Bitfehlererkennung?
  * Sender sendet nur legale Frames, die vom Medium korrumpiert werden
  * Hoffnung: Ein legaler Frame wird nie ein anderer legaler Frame, sondern ein illegaler, notwendig hierfür: nur eine gewisse Anzahl an Bitflips darf auftreten

### Parität
* Erzeugung eines redundanten Bit: Parität
  * ungerade Parität: füge ein Bit hinzu, sodass die Gesamtzahl an 1en ungerade ist
  * gerade Parität: füge ein Bit hinzu, sodass die Gesamtzahl der 1en gerade ist
* Angenommen der Empfänger erwartet immer gerade Parität, so kann er Fehler erkennen, sobald es eine ungerade Parität gibt

### Checksummen
* Zur Berechnung von Checksummen behandelt der Sender die Daten als Sequenz von binären Integers
* Gruppieren in zweier Kombis und aufaddieren von deren Werten um die Checksumme zu erhalten
* Positiv: Einfach zu berechnen
* Negativ: Erkennen nicht alle häufigen Fehler

### Hammingdistanz
Hammingdistanz = Anzahl an Stellen an denen sich zwei Frames x und y in binärer Darstellung unterscheiden lösbar mittels (x XOR y).

Generalisierung
* Um Bitfehler zu erkennen, ist eine Hammingdistanz von d+1 in der Menge der legalen Frames nötig
  * So, dass man unmöglich mit nur d Bitflips einen legalen Frame in einen anderen Schreiben kann
* Um Bitfehler korrigieren zu können ist eine Hammingdistanz von 2d+1 in der Menge der legalen Frames benötigt
  * So sind alle Frames die bis zu d Bits vom nächsten legalen Frame entfernt sind, noch mehr als d Bits zum anderen legalen Frame entfernt sind

### Frame Mengen - Code Books, Code
* Terminologie
  * Codebook = Menge von legalen Frames
  * Rate R von Code $S: R = log|S|/n$ (Effizienz)
  * Distanz d von Code $S: d = d(S)/n$ (Fehlererkennungs/korrekturmöglichkeiten)
* Kriterien für guten Code: hohe Distant und große Rate
* Konstruktion guter Codes schwer, Möglichkeit mehrerer Paritätsbits wappnet gegen Bündelfehler

### Cyclic Redundancy Check - CRC
* Effizient, hohe Erkennungswahrscheinlichkeit mit wenig Redundanzbits
* Funktion beruht auf polynomieller Arithmetik
  * Bitstrings als Repräsentanten von Polynomen
  * Koeffizienten 0 und 1 möglich, interpretiert als modulo 2
* Idee: Fasse die Stränge von Bits als Repräsentation der Koeffizienten des Polynoms auf
  * Bitstring mit (n+1) Bits = Polynom von Grad n
* Verwende Polynome um CR Bits zu berechnen
  * Definiere eine Generatorpolynom G(x) des Grades g
    * Sowohl Sender als auch Empfänger bekannt
    * Verwenden g Redundanzbits
  * Gegeben Nachricht M(x)
  * Sender berechnet Rest r(x) der Division $x^g*M(x)/G(x)$
  * Überträge $T(x) = x^g M(x)-r(x)$
    * T(x) ist restfrei Teilbar durch G(x)
  * Empfänger erhält m(x)
  * Berechnet den Rest der Division von m(x) durch G(x)

CRC Übertragung und Empfang
* Keine Fehler T(x) kommt korrekt an
* Bitfehler: T(x) ist verändert, dh. Koeffizienten wurden verändert
  * Es kommt also T(x) + E(x) an
* Auf Empfängerseite:
  * Empfange m(x) und berechne m(x) / G(x)
  * Fehlerfrei: m(x) = T(x)
  * Bitfehler: m(x) / G(x) = (T(x)+E(x))/G(x) = T(x)/G(x) + E(x)/G(x)
* Die Wahl von G(x) bestimmt die CRC Eigenschaften
* In der Anwendung werden sämtliche Fehler nach dem CRC-Check ignoriert
  * Fehler können dennoch auftretem, insbesondere sind Fehler meist berstend

### Rückwärtsfehlerkontrolle
Behandlung erkannter Fehler auf zwei Arten und Weisen
- Vorwärts: Sender sendet redundante Infos so, dass der Empfänger selbst ausbessern kann
- Rückwärts: Sender sendet redundante Infos so, dass der Empfänger fehlerhafte Pakete wahrscheinlich erkennt und Pakete in dem Fall nochmal verschickt werden können

Rückwärtskorrekturverfahrensprotokolle sind unter dem Namen Automatic Repeat Request (ARQ) bekannt:
* Send and Wait
* Go-Back-N
* Selective Reject

#### Send and Wait
* Sender schickt ein Paket, stellt sich einen Timer, wartet auf eine Quittung, und wenn keine ankommt, dann überträgt er es erneut
* Beschädigte Pakete werden vom Empfänger einfach verworfen
* Problem: Falls das ACK Paket verloren geht/ beschädigt wird, so kann dies der Sender nicht erkennen:
  * Schickt einfach neu, und der Empfänger hat plötzlich zwei Kopien des selben Pakets
* Lösung
  * Einführen von Sequenznummern, um zwischen verlorenen Paketen und Quittungen, sowie neuen und schon empfangenen Paketen zu unterscheiden
  * Konvention: Sende Sequenznummer des zuletzt korrekt empfangenen Pakets in der Quittung

##### Alternating Bit Protokoll
* Einführung der Sequenznummern 0 und 1 in den Nachrichten und ACKs
* Bedenke: ACKs nun mit doppelter Funktion
  * Bestätigen dem Sender, die Ankunft des Pakets
  * Erlauben es dem Sender eine weitere Nachricht zu senden

##### ARQ - Sliding Windows
> Effizienz\
> Definiert als die Rate der Zeit, in welcher der Sender neue Informationen sendet (für den fehlerfreien Kanal)\
> Effizienz = $\frac{T_{packet} }{ T_{packet} + d + T_{ack} + d}$

* Die Effizienz des einfachen Alternatingbitprotokolls ist gering, wenn die Verzögerung im Vergleich zur Datenrate hoch ist.

Verbesserung der Effizienz
* Ineffizienz von Alternatingbitprotokollen in Situationen mit großem Bandwith/Delay Produkt hängt mit der Wartezeit und dadurch ungenutztem Speicherplatz zusammen
* Dauerhaftes Senden führt zu höherer Effizienz, deshalb Pipelining von Paketen und Einführen eines größeren Sequenznummernraums

Sliding Windows
* Führe neuen Sequenznummernraum mit 2^n Sequenznummern ein, wobei nie alle gleichzeitig verwendet werden dürfen
* Verwende Sliding Windows sowohl beim Sender als auch beim Empfänger, um diese Nummern zu behandeln
  * Sendefenster = Menge an zum Versand freigegebenen Sequenznummern
  * Empfangsfenster = Menge an Sequenznummern welche zur gegebenen Zeit akzeptiert werden

###### Übertragungsfehler und Empfangsfenstergröße
* Annahme: Linklayer sollte alle Frames korrekt und in Reihenfolge zustellen, der Sender verwendet Pipelining
* Beim Verlieren von Paketen bei einer Empfangsfentergröße 1 werden alle folgenden Pakete verworfen

#### Go-Back-N
* Bei Empfangsfenstergröße 1 können alle auf einen verlorenen Frame gesendeten Frames nicht vom Empfänger verarbeitet werden
  * Sind out of Sequence und können nicht bestätigt werden
* -> Sender wird einen Timeout erfahren
  * Da alle Frames in der Zwischenzeit aber weitergesendet wurden, müssen diese erneut übertragen werden
* Go Back N ist leider ziemlich verschwenderisch mit den Ressourcen, minimiert aber den Overhead beim Empfänger

##### Selective Reject / Selective Repeat
* Empfänger kann nun einige Pakete puffern
* Der Empfänger sendet im Fehlerfall negative Acknowledgements
* Der Sender wiederholt die Übertragung von fehlenden Frames

##### Duplexoperation und Piggybacking
* Bisher Simplexoperation am oberen Serviceinterface, dh. Empfänger sendet ausschließlich ACKs zurück
* Wenn das obere Dienstinterface Full-Duplex unterstützt, dann wechsle Datenframes und ACK-Frames für eine gegebene Richtung ab
  * Stecke die ACK-Info für Richtung A ! B in die Datenframes für B ! A (Piggybacking)

#### Leistungsverhalten:
* Fehlerfreies Send and Wait:
  * S = 1/(1+2a) wobei a = T-prop / T-frame
* Fehlerbehaftetes Send and Wait:
  * S = (1-P)/(1+2a)
* Fehlerfreies Sliding Window:
  * Sei W die Anzahl an Frames, welche der Sender senden kann, bevor er auf Quittungen warten muss
  * Normalisierter Durchsatz: S = {1, falls W >= 2a+1, W/(2a+1) sonst}
* Selective Reject:
  * S = {1-P, falls W >= 2a+1, (W(1-P))/(2a+1) sonst}
* Go-Back-N:
  * S = {(1-P)/(1+2aP), falls W >= 2a+1, (W(1-P))/((2a+1)(1-P+WP)) sonst}

## Folgerung Kapitel 4
* Die meisten Probleme im Linklayer entstehen durch Fehler
  * Fehler in der Synchronisation erfordern nichttriviale Framingfunktionen
  * Fehler in der Übertragung erfordern Mechanismen diese zu Korrigieren und zu Verstecken, oder sie zu erkennen und zu reparieren
* Flusskontrolle ist oft eng in die Fehlerkontrolle integriert
  * Ist allerdings eine separate, auch getrennt implementierbare Funktion
* Wahl des Fehlerkontrollschemas beeinflusst die Performance
* Verbindungsaufbau und -abbau muss noch behandelt werden

---
# Kapitel 5: Medium Access Control (MAC)
## Einführung: Multiple Access Link und Protokolle
* Point to Point
* Broadcast (geteiltes Medium)
* Einzelner geteilter Broadcastkanal
* zeitgleiche Übertragung von zwei oder mehr Knoten: Interferenz

### Multiple Access Protokoll
* Verteilter Algorithmus, der bestimmt, wie Knoten auf ein geteiltes Medium zugreifen
* Oftmals kein out-of-Band Kanal für die Koordination

### Broadcastkanal mit Rate R b/s
* Will nur einer Senden so kann er dies mit R, wollen M Instanzen senden, so sollen sie dies in R/M können.
* Völllig dezentralisiert und so einfach wie möglich

### Statisches Multiplexing
* Eine einzelne Ressource kann statisch gemultiplext werden indem:
  * Man feste Sendezeiten einräumt
  * Mehrere Frequenzbänder verwendet

### Berstender Verkehr (Burst)
* großes Problem, da
  * die Ressource groß genug sein muss um mit der Datenrate sofort zurecht zu kommen
  * auf den durchschnittlichen Verbrauch ausgelegt sein muss und aber Puffer benötigt

### Statisches multiplexing berstenden Verkehrs - Verzögerung
* Basisfall: Kein Multiplexing, einzige Trafficquelle mit durchschnittlicher Rate P und Kapazität C
  * Verzögerung ist T
* Multiplexing: Unterteile Ressource in N Quellen mit gesamter totalen Rate, statisch gemultiplext
  * Verzögerung T-FDM = N \* T
  * Unabhängig von FDM, TDM
* -> Multiplexing erhöht das Delay um das N-fache

### Dynamische Kanalzuweisung
* Statisches Multiplexing nicht geeignet für berstenden Verkehr
* Alternative: Weise der Quelle welche Senden will den Kanal/Link zu

#### Annahmen für die dynmaische Kanalzuweisung
* Stationsmodell:
  * N unabhängige Stationen
  * Mögliches Lastmodell: Wahrscheinlichkeit des Generierens eines Pakets im Intervall t ist x*T, mit x konstant
* Einkanalannahme:
  * Nur ein Kanal für alle Stationen und für alle Nachrichten
* Kollisionsannahme:
  * Nur je ein Frame zeitgleich fehlerfrei übertragbar
* Zeitmodell:
  * Kontinuierlich: Übertragungen können jederzeit stattfinden
  * Geslottet: Zeit ist in Slots eingeteilt, Übertragung kann nur an Slotgrenzen beginnen
* Carrier Sensing:
  * Stationen können (oder auch nicht) erkennen, ob der Kanal frei oder in Benutzung ist
  * Falls Kanal als belegt angesehen, so wird nichts übertragen

##### Zahlen von Merit
* Wie ist die Effizienz eines dynamischen Kanalzuweisungssystems zu bewerten?
  * Bei hoher Last sollen möglichst viele Pakete durchkommen
  * Bei niedriger Last soll die Verzögerung so gering als mögich sein
  * Fairness - Wird jede Station gleich behandelt?

###### Durchsatz und angebotene Last
* Last G: falls > 1 so Überladung
* Ideal: S gleicht angebotener Last solange G < 1, S = 1 falls G <= 1 (nicht sehr realistisch)

### Grundlegende Optionen für MAC
* Kollisionsfreie Protokolle
* Limited Contention Protokolle (beschränkt Kollisionsbehaftet)
* Kollisionsprotokolle

#### Kollisionsbehaftete Protokolle
* ALOHA:
  * Jeder sendet einfach sobald er etwas zu senden hat, keine Benachrichtigung über den Erfolg einer Übertragung möglich
  * Paketübertragung bei ALOHA ist nur dann erfolgreich, wenn es keine weitere Übertragung in zwei Paketzeiten gibt -> mittlerer Erreichbarer Durchsatz < 20%
* Slotted ALOHA:
  * Verwende nun Zeitslots (werden als irgendwie verfügbar angesehen)
  * Dadurch Verdoppelung des Durchsatzes auf ca 36%
  * Problem nach wie vor, der Durchsatz bricht zusammen, sobald sich die Last erhöht

### Carrier Sensing
* Höre bevor du redest, und sende nichts, wenn das Medium gerade belegt ist
* 1-Persistent CSMA
  * Falls belegt, so warte bis frei und sende dann -> Probleme entstehen, wenn mehrere nach der jetzigen Nachricht senden wollen
* Non-Persistent CSMA
  * Wenn Kanal frei so übertrage, wenn Kanal belegt, so warte eine zufällige Zeit vor dem nächsten Freiheitstest
  * Performance abhängig von der Zufallsverteilung, besser bei hoher Last, bei geringer Last nur unnützes Warten
* P-Persistent CSMA
  * Kombiniert bisherige Ideen + geslottete Zeit
  * Warte ständig auf freiwerden des Kanals,
    * übertrage dann aber nicht sofort, sondern werfe eine Münze mit WK p, und sende mit WK p oder Warte mit 1-p auf nächsten Zeitslot und prüfe wieder

#### CSMA und die Ausbreitungsverzögerung
* Problem jedes CSMAs: Ausbreitungsverzögerung
* Zwei Stationen seien bereit zum Senden zur Zeit t und t+e
  * Zum Zeitpunkt t ist der Kanal frei, und Stationen durch Verzögerung d > e getrennt
  * -> Station 2 kann bereits begonnene Übertragung von Station 1 nicht erkennen und sendet -> Kollision

#### Collision Detetion - CSMA/CD
* Bei Kollision zweier Pakete geht viel Zeit durch die Beendigung der Übertragung verloren
* Abhängig vom physischen Layer können Kollisionen erkann werden
  * Notwendig: Sender muss während des Sendens in den Kanal hören und dies mit seinem gesendeten vergleichen , falls dies nicht identisch ist, so deklariere es als Kollision
* Sollte eine Kollision aufgetreten sein, so warte eine zufällige Zeit

#### Wahl einer zufälligen Wartezeit
* Einfach: Wähle einen aus k Slots
* Aber wie beschränkt man k nach oben?
  * Kleines k: kurze Verzögerung, mehr Kollisionen
  * Großes k: große Verzögerung, weniger Kollisionen
  * -> Adaptiere k an die Verkehrslast

#### Adaption von k an die Last
* Verwende Kollisionen als Indikator für ein zu kleines Wettbewerbsfenster
* Frage: Wie erhöht man k und wie verringert man es wieder?

#### Binary exponential Backoff
* Erhöhe nach Kollisionen:
  * Verdopplung von k bis zu einer gewissen Größe
* Verringern von k:
  * Kompliziert: Wenn genug Frames nicht kollidiert sind, so reduziere k
  * Einfach: Starte jedesmal wieder bei k = 1

### Wettbewerbsfreie Protokolle
* Kollsionen bereiten Probleme -> Medium ohne Wettbewerb nutzen
* Beispiel: Statisches TDMA (Time Division Multiple Access)
* Ansätze um die Nachteile von TDMA zu kompensieren:
  * Zuweisung der Zeitslots nur an sendebereite Knoten
    * Zentraler Master vergibt Rederechte
    * Tokenring
    * Stationen übermitteln Sendewunsch

### Polling und Tokenweitergabe
Polling:
* Masterknoten läd Slaveknoten zum Übertragen in Reihenfolge ein
* Probleme: Polling Overhead, Latenz, Single Point of Failure

Tokenweitergabe:
* Kontrolltoken wird von einem zum anderen Knoten übertragen
* Probleme: Token Overhead, Latenz, Tokenverlust

### Bit-Map-Protokoll
* Stationen melden Sendewunsch während eines Reservierungsslots an

Eigenschaften:
* Verhalten bei geringer Last:
  * Wenn kaum ein Paket versendet werden soll, so wiederholt das Medium die Contentionslots - > Wartezeit
* Verhalten bei großer Last:
  * Hoher und stabiler Durchsatz mit vernachlässigbarem Overhead
* Bit-Map ist ein Carrier Sense Protokoll

### Limited Contention Protokolle
* Wünschenswert: Protokoll mit
  * geringer Verzögerung bei wenig Last
  * hohem Durchsatz bei viel Last
* Idee 1:
  * Anpassen der Stationsanzahl per Contentionslot
  * Contentionslots sind gut für den Durchsatz, bei geringer Last können wir es uns aber nicht leisten, auf die Antworten zu warten -> Stationen müssen sich dynamisch einen Slot teilen
* Idee 2: Adaptives Baumprotokoll
  * Verwende verschiedene Auflösungslevel für die Wettbewerbsslots
    * Im höchsten Level teilen sich alle einen Slot
    * Wenn nur ein Node einer Gruppe senden will, so darf er das
    * Wenn es mehr als einer ist, so kommt es zur Kollision im Contentionslot -> verdopplte die Slots und halbiere die Stationsanzahl pro Slot
    * Rekursion!

## Fallstudie Ethernet
### Topologien
* Bustoplogie := Alle Geräte sind an einem Kabel angebunden und sind in einer Kollisionsdomäne
* Sterntopologie :=  einfachere automatische Verwaltung und Wartung bei fehlerhaften Adaptern

#### Unzuverlässiger, verbindungsloser Dienst
* Verbindungslos:
  * Kein Handshake
* Unzuverlässig:
  * Keine ACKs oder NACKs
  * Datagrammstream kann Lücken haben, welche gefüllt werden müssen, falls benötigt

#### Physisches Layer
* Typischerweise Manchestercodierung

#### Ethernet verwendet CSMA/CD
* Keine Slots
* Carrier Sense: Niemand überträgt, wenn er merkt, dass ein anderer Adapter gerade sendet
* Collision Detection: Übertragender Adapter bricht ab, wenn er Kollisionen bemerkt
* Random Access: Warten einer zufälligen Zeit vor erneuter Übertragung

##### Ethernet - CSMA-CD Algorithmus
1. Adapter erhält Datagramm von der Netzwerkschicht und erstellt Frame
2. Falls Kanal frei, so sendet der Adapter den Frame, falls dem nicht so ist, warte bis Kanal frei
3. Wenn erfolgreich übertragen, dann ist der Adapter mit dem Frame fertig
4. Falls eine andere Übertragung zeitgleich stattgefunden hat, so stoppe und sende ein Störsignal
5. Nach dem Abbrechen geht es in den Exponential Backoff: Nach n-ter Kollision wähle ein K aus {0,1,2,…,2^(m-1)} mit m = min{10,n}: Adapter wartet nun K * 512 Bitzeiten und kehrt zu 2 zurück

* Jam Signal: Stellt mit 48 Bits sicher, dass alle anderen die Kollision mitbekommen haben
* Bitzeit: 0.1 µs bei 10 Mbps Ethernet
* Exponentiall Backoff:
  * wähle zuerst K aus {0,1}, dann ab der zweiten Kollision aus {0,1,2,3} und nach 10 Versuchen aus {0,1,2,3,…,1023}

#### Effizienz
efficiency = $\frac{1}{ (1+5 * (t_{prop}/t_{trans}))}$

#### Hubs
* essentielle physical-layer-repeater
* Eingehende Bits werden an alle Ausgänge mit selber Rate und ohne Puffern verteilt
* Kein CSMA-CD am Hub, Aufgabe der Adapter\
-> Hub stellt nur elektronische Verbindung her -> eine Kollisionsdomäne

#### Switch
* nicht nur eine einfache elektrische Verbindung für sternförmige Topologie
* Wie tauscht man Pakete zwischen Kollisionsdomänen aus?
  * Switches enthalten Puffer, welche direkt ankommende Pakete zwischenspeichern, bevor sie diese weiterleiten

#### Geschwindigkeiten der Ethernetversionen
1. Switched Ethernet - mehrere Stationen über ein Kabel
2. Fast Ethernet - wie Switched nur mit 10ns Bitzeit
3. Gigabit Ethernet - jedes Kabel hat genau zwei Maschinen angehängt
   * Mit Switch:
     * Keine geteilten Kollisionsdomönen, benötigen kein CSMA-CD
     * Fullduplexoperation auf jedem Link
   * Mit Hub:
     * Kollisionen, Halbduples, CSMA-CD
     * Maximale Kabellänge 25 Meter

## Zusammenfassung Kapitel 5
* MAC Protokolle sehr wichtig, wenn man sich ein Medium mit vielen Anderen teilen will
* Hauptkategorien: Collision, Collision Free und limited contention
* Maßzahlen zur Beurteilung: Durchsatz, Verzögerung und Fairness
* Wichtige Fallstudie: Ethernet - Lehre: Halte es einfach!

---
# Kapitel 6 Internetworking
## LAN Verbindungen
* Klassisches Ethernet - Ein Kabel eine Kollisionsdomäne
* Funktioniert für einige Geräte, kollabiert ab gewisser Größe, CSMA-CD kann ebenfalls nicht mehr mithalten

### Gründe für mehrere LANs
* Beschränkte Anzahl an Nutzern in einem einzelnen Netz
* Geographische Verteilung - würde zu ungeheuren Round Trip Zeiten führen
* Zuverlässigkeit - Defekte Sender würden ständig zwischenfunken
* Sicherheit - Promiscous Operation - Begrenzung möglichen Schadens

### Möglichkeiten des Überwindens der Begrenzungen
* Application Layer <-> Application Gateway
* Transport Layer <-> Transport Gateway
* Network Layer <-> Router
* Data Link Layer <-> Bridge, Switch
* Physical Layer <-> Repeater, Hub

## Physical Layer Verbindungen
### Repeater
* Physical Layer Gerät, verbindet zwei Kabel und verstärkt die ankommenden Signale und leitet dieses weiter
* Versteht den Inhalt der Pakete nicht und interessiert sich nicht dafür

### Hub
* Physical Layer Gerät, verbindet mehrere Kabel elektrisch
* Alle verbundenen Kabel formen eine Kollisionsdomäne
* Versteht den Inhalt der Pakete nicht und interessiert sich nicht dafür

-> Lösungen nicht zufriedenstellend: Lösen die wirklich interessanten Probleme nicht

## Data Link Layer
### Switch
* Verbindet mehrere Terminals, ohne eine Kollisionsdomäne zu erzeugen
* Speichert Link-Layer-Frames und leitet diese weiter
* Wenn ein Paket auf ein Segment geleitet werden muss, wird CSMA-CD zum Zugriff verwendet
* Inspiziert Adressen ankommender Pakete und leitet diese weiter (benötigt Puffer und Wissen, wo welches Terminal steht)

Weiterleitung: Wie weiß man, wo was hingeleitet werden muss? -> Routingproblem

#### Pfaderkennung - Selbstlernen
* Jeder Switch hat eine Switchtabelle
* Eintrag: (MAC-Adresse, Interface, Zeitstempel)
* Beim Empfang eines Frames lernt der Switch den Ort des Senders kennen (Rückwärtslernen)

#### Weiterleiten
* Falls Ziel bekannt so prüfe, ob
  * es in das selbe Segment gehört aus dem es kommt -> verwerfen
  * sonst leite es passend weiter
* andernfalls flute das Netzwerk damit

### Bridges
* Switches sind beschränkt, da sie nur einfache Terminals verbinden
* Jedes mit einer Bridge verbundene Netzwerk ist eine eigene Kollisionsdomäne, und auch verschiedene LAN-Typen können miteinander verbunden werden

#### Rückwärtslernen in Bridges - Bootstrapping
* Algorithmus
  * Flute, falls nicht bekannt wohin gesendet werden muss, oder
  * verwerfe, wenn bekannt, dass es nicht nötig ist, oder
  * leite spezifisch weiter, wenn das Ziel bekannt ist

Probleme: Durch Fluten können Paketloops entstehen
##### Lösung 1: Einschränken des Flutens
* Verhindern des unendlichen loopens indem gespeichert wird, was schon weitergeleitet wurde
* Dies benötigt Zustände und Einzigartigkeit und Pakete müssen unterscheidbar sein
* Großer Overhead
  * Zustände sind problematisch, da das Durchsuchen Zeit kostet

##### Lösung 2: Spanning Trees
* Wandle das Netzwerk ein einen zyklenfreien Graph und berechne darauf den Spannbaum
  > Definition Spannbaum:\
  > Gegeben sei ein Graph G=(V,E), ein Spannbaum T = (V,E-T) ist ein Subgrap von V, wobei E-T ein Teil von E ist, welcher ein Spannbaum, der verbunden und azyklisch ist.

### Higher-Layer Verbindungen
#### Router
* Bisher haben alle Geräte Adressen entweder ignoriert, oder arbeiteten mit MAC-Layer Adressen
* Für Verbindungen außerhalb eines LANs sind solche Adressen nicht ausreichend
  * Hauptproblem: flache Adressstruktur, nicht skalierbar
* Benötigen ausgefeiltere Adressstruktur

#### Gateways
* Wenn selbst Router nicht ausreichend, dann sind Higher-Layer-Verbindungen notwendig
  * Arbeit auf dem Transportlevel und oberhalb, zum Beispiel für Transcodierung

### Weitere Probleme mit LAN/LAN Verbindungen
* LAN meist lokal eingesetzt, aber logische Distanz sollte auch berücksichtigt werden
* Idee: Platziere in das physische LAN ein virtuelles LAN (VLAN)
* Konfigurationstabellen bezüglich VLAN Zugehörigkeit benötigt

## Zusammenfassung Kapitel 6
* einzelne LANs sind nicht ausreihend um Kommunikationswege für größere Installationen bereitzustellen
* Verbindung einzelner LANs nötig
  * Physisches Layer - Repeater und Hub
  * Data-Link-Layer - Bridges und Switches
  * Netzwerklayer - Routing
  * Higher-Layer - Gateways
* Probleme:
  * redundante Bridges ermöglichen Trafficfluten, benötigen Spannbaumalgorithmen
  * Einfache Adressen nicht skalierbar -> benötigen Router

---
# Kapitel 7: Netzwerklayer
## Bauen großer Netzwerke
* Internetworkingmechanismen helfen Paketen an ihr Ziel zu gelangen
  * Hubs: Broadcast
  * Switch: Sende an direkt verbundenes Netzwerk
  * Bridges: Fluten (verursacht Probleme)
* Fluten ist keine gute Idee für große Netzwerke -> Spannbäume sind aber schonmal gut

## Netzwerklayerfunktionen
* Weiterleiten: Bewege Pakete vom Routereingang auf den entsprechenden Ausgang
* Routing: Berechnen der Route, die die Pakete von Quelle bis zum Ziel gegangen sind

### Weiterleitung
* Wie bekomme ich Pakete von einem Netzwerk ins Andere? -> Verwende Switches/Bridges/Router
* Tatsächliche Routingtabellen enthalten IP-Adressen, Flags, Netzmasken, etc.

### Durchsuchen der Routingtabelle
* Suche nach übereinstimmender Hostadresse (Flag H gesetzt)
* Suche dann nach passender Netzwerkadresse
* Drittens, Suche nach einem Defaulteintrag
  * Führe netstat -rn auf der Maschine aus und finde die Einträge der Routingtabelle
  * Erlaubt es uns einen einzelnen Eintra für eine Liste an Einträgen zu haben, welche alle den selben next-hop Wert haben
* Frage: Wie kommt man nun auf die in der Routingtabelle gespeicherten Informationen?

## Zusammenspiel zwischen Routing und Weiterleitung
### Verbindungsaufbau
* Dritte wichtige Komponente in manchen Netzwerkarchitekturen
  * ATM, Frame Relay, X.25
* Bevor Datagramme fließen, werden zwei Hosts und Router eine virtuelle Verbindung aufbauen
* Netzwerk und Transportlayer Verbindungsdienste:
  * Netzwerk: Zwischen zwei Hosts
  * Transport: Zwischen zwei Prozessen
* Im Internet gibt es keinen Verbindungsaufbau auf dem Netzwerklayer

### Netzwerkservicemodell
Frage: Welches Servicemodell für die Übertragung von Datagrammen vom Sender an den Empfänger verwenden?
* Dienste für individuelle Datagramme:
  * Garantierte Zustellung mit weniger als 40msec Verzögerung
* Dienste für einen Datagrammstrom:
  * Zustellung in Sendereihenfolge
  * Garantierte Mindestbandbreite
  * Begrenzungen bei den Abständen von Paketen

### Virtuelle Schaltkreisbasierte vs. Datagrammorientierte Netzwerke
### Verbindungslose und Verbindungsbasierende Dienste auf dem Netzwerklayer
* Datagrammnetzwerke = verbindungsloser Netzwerklayerdienst
* VC Netzwerke = verbindungsbasierter Netzwerklayerdienst

### Virtuelle Schaltkreise
* Rufaufbau bevor überhaupt etwas übertragen werden kann + Rufabbau danach
* Jedes Paket überträgt einen VC-Identifier
* Jeder Router auf dem Weg behält einen Zustand für jede Verbindung vor und es können Link und Routerressourcen an einzelne Verbindungen zugeteilt werden

### Implementierung virtueller Schaltkreise
* Besteht aus einem Pfad von der Quelle zum Ziel, sowie
* VC-Nummern, für jeden Link auf dem Pfad
* und Einträgen in Weiterleitungstabellen in Routern auf dem Weg
* Pakete welche zum VC gehören tragen eine VC-Nummer
* VC-Nummern müssen auf jedem Link geändert werden (neue kommen von Weiterleitungstabellen)

### Weiterleitungstabellen
* Aufbau: Incoming Interface, Incoming VC, Outgoing Interface, Outgoing VC

### VC Signalprotokolle
* Verwendet zum Aufbau und zur Terminierung von VCs, heutzutage nicht mehr verwendet

### Datagrammnetzwerke
* Kein Verbindungsaufbau auf dem Netzwerklayer
* Router halten keine Zustände für Ende-zu-Ende Verbindungen
* Pakete werden anhand ihrer Zielhostadresse weitergeleitet (-> verschiedene Pfade für selbes Ziel)

### Longest Prefix Matching
* Wähle diejenige Adresse aus der Tabelle, welche die größte Anzahl führender Adressbits mit der gegebenen gemein hat

### Datagramm vs. VC-Netzwerk
* Internet
  * Datenaustausch zwischen Computern
  * "intelligente" Endsysteme, können z.B. Fehlerkontrolle und Fehlerkorrektur implementieren
  * Viele verschiedene Linktypen, d.h einheitlicher Dienst nahezu ausgeschlossen
* ATM
  * Geht aus der Telefonie hervor
  * Konzept menschlicher Kommunikation:
    * Striktes Timing, Zuverlässigeit benötigt
  * "Dumme" Endsysteme, d.h. Komplexität liegt innerhalb des Netzwerkes

## Wie ist ein Router eigentlich aufgebaut?
* Zwei Hauptfunktionalitäten:
  * Ausführen von Routingalgorithmen und Protokollen
  * Weiterleiten von Datagrammen von eingehenden auf ausgehende Links

### Eingangsportfunktionen
Dezentralisiertes Switching:
* Gegebenes Datagrammziel, finde passenden Ausgangsport durch Benutzung von Weiterleitungstabellen
* Queuing, falls Pakete schnelller ankommen als man sie weiterleiten kann

### Switching Fabric
1. Switching mittels Speicher
   * Herkömmliche Rechner mit Switching unter direkter CPU-Kontrolle
   * Kopieren der Pakete in den Systemspeicher
   * Geschwindigekeit limitiert durch die Speicherbandbreite
2. Switching mittels BUS
   * Übertragung von Datagrammen intern über einen Bus
   * Switchinggeschwindikeit limitiert durch die Busbandbreite
   * typ. 1Gbps Bus, ausreichend für Heim und Businessrouter
3. Switching mittels Verbindungsnetzwerk (Crossbar)
   * Überwinden der Bandbreitenbeschränkungen von Busen
   * Design: Fragmentierung von Datagrammen in Zellen fester Größe, wobei nun die Zellen durch das Fabric geswitcht werden
   * Bis zu 1.28 Tbps Switchinggeschwindigkeit

### Ausgangsports
* Pufferung nötig, sobald Pakete vom Fabric schneller ankommen, als die Ausgangsrate ist
* Schedulingdisziplin wählt aus den zu übertragenden Datagrammen

### Ausgangsportwarteschlangen
* Probleme: Verzögerung und Verluste durch Pufferüberläufe möglich

### Eingangsportwarteschlangen
* Fabric langsamer als Kombination von Eingangsports -> Schlangenbildung
* Head-of-the-Line (HOL) blocking: Datagramme am Anfang der Warteschlange hindert andere in der Warteschlange daran weiter zu kommen
* Probleme: Warteschlangenverzögerung und Verluste durch Pufferüberläufe

## IP - Datagrammformat und Paketverarbeitung
### IP Paketformat
* Version: Versionsnummer des eingesetzten IP
* IHL: IP Header Length in 32 Bit Worten
* Typ des Dienstes: Infos zur Priorisierung
* Totale Länge: Die gesamtlänge in Bytes inklusive Header
* Identifier: Wenn Fragmentierung auftritt, bekommt jedes zugehörige Paket den selben Identifier
* Flags:
  * DF: don't fragment
  * MF: more fragments, alle außer das letzte Paket haben dies gesetzt
* Fragment Offset: Position des Fragments im ursprünglichen Paket
* TTL: Zähler für die Hopanzahl, wird an jedem Router dekrementiert, sobald gleich 0 -> verwerfen
* Protokoll: Spezifiziert verwendetes Protokoll
* Headerchecksum: Erlaubt Verifizierung der Inhalte im IP Header
* Quell und Zieladressen: identifizieren der Quelle und des Ziels
* Optionen: bis 40 Byte, zur Erweiterung verwendet

### IP Fragmentierung und Reassemblierung
* Netzwerklinks haben eine MTU (größter Linklevelframe) -> verschiedene Linktypen, verschiedene MTUs
* Große IP Datagramme werden innerhalb des Netzes unterteilt
  * Aus einem Datagramm werden mehrere, die erst beim Zielsystem wieder zusammengesetzt werden
  * IP Header Identifizieren und Ordnen die neuen Pakete

### IP Adressierung
#### Scheitern von einfachen Adressierungsmethoden
* Bei MAC/LLC: Jedes Gerät mit globaler einzigartiger Adresse -> Probleme: Jede Bridge mit extra Eintrag für jedes Gerät -> massiver Speicher- und CPU-Overhead

#### Adressierung und hierarchisches Routing
* Benötigen eine Adressstruktur welche hierarchische Routingstrukturen respektiert und ausdrückt

#### Nähe
* Achtung:
  * Proximity: Beschreibt physische Nähe
  * Closeness: Beschreibt strukturelle und logische Nähe mit kurzer Distanz

#### internetnamen und Adressen
#### Klassen von IP-Adressen
* Class A: sehr große Organisationen, bis 16 Millionen Hosts
* Class B: große Organisationen, bis 65 Tausend Hosts
* Class C: kleine Organisationen, bis 255 Hosts
* Class D: Multicast, keine Netzwerk/Host Hierarchie
* Class E: reserviert
* Loopback: 127.xxx.xxx.xxx ist zum Testen reserviert, hierauf versendete Pakete werden als eingehende behandelt
* Broadcast: alles 1en
* Adresshierarchie:
  * Jede Adresse mit Hostteil und Netzwerkteil
  * Class A,B,C unterstützen nur zwei Level der Hierarchie
  * Aber weitere Strukturierung des Hostteils in Subnetze möglich

### IP-Adressierung
* IP Adresse: 32 Bit Identifier für Hosts oder Routinginterfaces
* Interface: Verbindung zwischen Host und dem physischen Link
  * IP Adressen werden an das jeweilige Interface vergeben

#### Subnets
* IP Adresse:
  * Subnetteil
  * Hostteil
* Was ist ein Subnet?
  * Geräteinterfaces mit selbem Subnetteil in der IP Adresse können untereinander ohne Router kommunizieren
* Um die Subnetze herauszufinden entferne jedes Interface von dessen Host oder Router. Somit erschaffte Inseln sind isolierte Netze, also Subnetze

#### IP Adressen
* Classfull-Adressierung:
  * Ineffiziente Nutzung von Adressräumen
  * Bsp: Class B Netz allokiert Adressen für 65k Hosts, selbst wenn nur 2k Adressen benötigt
* CIDR - Classless Inter Domain Routing:
  * Netzwerkportion von Adressen beliebiger Länge
  * Adressformat a.b.c.d/x, wobei x die Anzahl an Bits in der Netzwerkportion der Adresse darstellt

#### CIDR: Classless Inter Domain Routing
* Überwinden der Klassengrenzen durch Supernetting
* ISPs können nun Class C Blocks zu einem großen Block zusammenfassen
* "Longest match routing" auf maskierten Adressen
* Beispiel: Alle in Europa vergebenen Adressen teilen sich einen gemeinsamen Prefix -> Nur ein Eintrag für alle Verbindungen nach Europa in den meisten amerikanischen Routern

#### Wie bekommt man eigentlich eine IP-Adresse?
* Hart eincodiert in einer Konfigdatei
* DHCP: Dynamic Host Configuration Protocol: beziehe die Adresse dynamisch von einem Server

#### Wie kommt das Netzwerk eigentlich an seinen Subnetpart von IP-Adressen?
* Der Provider stellt eine allokierte Portion des Addressraums des ISPs bereit

### IP Adressierung: Allokation von Adressen
Woher bekommt ein ISP einen Adressblock?\
-> ICANN: Internet Corporation for Assigned Names and Numbers
* Allokiert Adressen
* Verwaltet DNS
* Weist Domainnamen zu und löst Konflikte

#### NAT - Network Address Translation
* Motivation: Knappheit an IP-Adressen
* Idee:
  * Lokale Netzwerke haben nur eine der Außenwelt bekannte IP-Adresse, somit hat nicht jedes Gerät eine vom ISP bereitgestellte Adresse
* Vorteile:
  * Möglichkeit intern Adressen zu vergeben ohne die Außenwelt informieren zu müssen
  * Wechsel des ISPs möglich, ohne intern Adressen zu verändern
  * Geräte im Netzwerk nicht von außen ansprechbar (Sicherheitsfaktor)
* 16 Bit Portnummernfeld -> 60 000 simultane Verbindung mit nur einer einzigen LAN-Side Adresse
* NAT ist allerdings kontrovers diskutiert:
  * Router sollten nur bis Layer 3 verarbeiten
  * Verletzt das Ende-zu-Ende Prinzip
  * Adressmangel sollte durch IPv6 gelöst werden

#### Schließen der letzten Lücke: ARP
* Was passiert, wenn ein Paket bei seinem Zielnetzwerk ankommt?
  * Wie wandelt man eine IP-Adresse in eine MAC-Adresse, welche dem zugehörigen Gerät gehört?
* Einfachste Lösung: Schreie!
  * Broadcast auf das LAN, mit der Frage, welcher Node IP X.X.X.X hat
  * -> Antwort des Nodes mit der MAC-Adresse -> Zustellung möglich
* ARP - Adress Resolution Protocol

##### ARP Protokoll im gleichen LAN
* A möchte B ein Datagramm senden, aber Bs MAC ist nicht in As ARP Tabelle
* A broadcastet ein ARP-Anfrage-Paket, welches Bs IP-Adresse enthält
  * Ziel-MAC = FF-FF-FF-FF-FF-FF
  * Alle Maschinen im LAN erhalten die Anfrage
* B erhält das ARP-Paket, und antwortet A mit seiner MAC
* A speichert das IP to MAC Adresspaar in seiner ARP Tabelle bis die Information veraltet ist
* ARP ist eine Plug-and-Play Technologie (Nodes erstellen ihre Tabellen selbstständig)

##### Routing in ein anderes LAN
* A erstellt Datagramm mit Quelle A und Ziel B
* A verwendet ARP um Rs MAC-Adresse für die IP hier 111.111.111.110 zu erhalten
* A erstellt Link-Layer-Frame mit Rs Macadresse als Ziel, Inhalt: A zu B Datagramm
* As Adapter sendet den Frame, Rs Adapter erhält diesen
* R entfernt das IP-Datagramm vom Ethernetframe und sendet es ans Ziel B
* R verwendet ARP um Bs Adresse zu erhalten
* R erstellt einen Frame, welcher das A zu B Datagramm enthält, und sendet diesen zu B

## ICMP und IPv6
### ICMP: Internet Control Message Protocol
* Verwendet von Hosts und Routern um auf Netzwerkebene Informationen auszutauschen
  * Fehlermeldungen oder Echo-Anfragen
* In Netzwerkebenen oberhalb von IP werden ICMP Nachrichten als IP Datagramme versendet
* ICMP Nachrichten: Typ, Code + erste 8 Bytes des den Fehler auslösenden IP-Datagramms

#### Traceroute und ICMP
* Quelle sendet Serie von UDP Nachrichten ans Ziel, jeweils immer mit TTL+1
* Wenn das n-te Datagramm am n-ten Router ankommt, so verwirft er dieses, sendet aber eine ICMP Nachricht (Typ 11, Code 0) an die Quelle, welche Namen und IP des Routers enthält
* Zurück an der Quelle wird die RoundTripTime errechnet, traceroute macht dies drei mal
* Stoppkriterien:
  * UDP Segment erreicht das Ziel
  * Ziel gibt ein "host unreachable" zurück (Typ 3, Code 3)

## IPv6
* Motivation:
  * 32 Bit Adressraum bald ausgeschöpft
  * Headerformat hilft bei schneller Verarbeitung und Weiterleitung
  * Header nun als Hillfmittel für QoS
* IPv6 Datagrammformat
  * Header mit 40 Byte Größe (also 20 Byte mehr als bei IPv4)
  * Fragmentierung ist nicht mehr erlaubt

### IPv6 Header
* Priority: Signalisiert die Priotität der Datagramme im Fluss
* Flow Label: Identifiziert Datagramme im selben Fluss
* Next Header: Identifiziert das Layer der höheren Schicht für Daten

### Weitere Veränderungen zu IPv4
* Checksummen -> komplett entfernt
* Optionen -> Erlaubt, aber außerhalb des Headers
* ICMPv6 -> Zusätzliche Nachrichtentypen + Multicastgruppenmanagementfunktionen

### Übergang von IPv4 zu IPv6
* Nicht alle Router können gleichzeitig aktualisiert werden -> Frage: Wie kann das Netzwerk mit einer Mischung aus beiden Versionen zurechtkommen?
* Lösung: Tunneln:
  * IPv6 wird als Nutzlast in IPv4 Datagrammen mitgeschickt
  * Rückschläge -> Zusätzlicher IPv4 Header
  * Verarbeitungsoverhead an den Tunnelendpunkten
  * Keine Priorisierung möglich

## Routing Algorithmen
### Überblick über Routingalgorithmen
* Ein Router führt einen Routingalgorithmus aus, um zu entscheiden, an welchem Ausgang ein eingehendes Paket weiter übertragen werden sollte.
  * Verbindungsorientiert: nur beim Verbindungsaufbau
  * Verbindungslos: entweder für jedes Paket oder periodisch ausgeführt
* Oftmals unter Verwendung von Metriken
  * Zuweisung eines Kostenfaktors an jeden Link, bspw. Anzahl an Hops, Kosten in € eines Links,…
* Zwei grundlegende Typen existieren:
  * Nichtadaptive Routingalgorithmen: Nehmen keine Rücksicht auf aktuellen Netzwerkzustand (z.B. Fluten)
  * Adaptive Routingalgorithmen: Berücksichtigen aktuellen Netzwerkzustand (z.B. Distanzvekotrrouting, Link State Routing)

### Fluten
* Strategie: jedes eingehende Paket wird auf jede ausgehende Linie geschickt, außer auf die Herkunftslinie
* Reduzierung der Nummer an Duplikaten:
  * Hopzähler im Paketheader, sodass das Paket nach gewisser Anzahl an Hops verworfen wird
  * Füge im ersten Router Sequenznummern in jedes Paket ein, welches vom Host empfangen wird. Jeder Router beinhaltet eine Tabelle, welche Sequenznummern er vom first-hop Router bekommen hat, daraufhin verwirft er alle Pakete, welche er bereits gesehen hat.

#### Mögliche Anwendungsfelder fürs Fluten
* Militärische Anwendungen:
  * Ziel soll immer erreicht werden können
* Updaten von verteilten Datenbanken
* Netzwerke mit häufigen Topologiewechseln

### Zufallsrouting
* Jedes ankommende Paket wird auf einen zufälligen Ausgang geschickt, außer auf den Quellausgang -> es bahnt sich seinen Weg sozusagen durch den Router

### Adaptive Routingalgorithmen
* Probleme nichtadaptiver Algorithmen:
  * Keine Anpassungsmöglichkeit auf stark schwankendes Verkehrsaufkommen
  * Kein ausreichend guter Umgang mit berstendem Verkehr
* Drei Grundtypen
  * Zentralisiertes adaptives Routing
  * Isoliertes adaptives Routing - benötigt keinen Informationsaustausch zwischen Routern
  * Verteiltes adaptives Routing - Router tauschen periodisch Infos aus und aktualisieren Weiterleitungstabellen

#### Zentralisiertes adaptives Routing
* Strategie:
  * Anpassen an die vorherrschende Verkehrslast
  * Ein Routingkontrollcenter muss ins Netzwerk eingebaut sein, welches periodisch den Linkstatus der Router erhält und kürzeste Routen berechnet und diese an die Router sendet
* Probleme:
  * Ausfall des Controllers sorgt für nichtadaptives Routing
  * Skaliert nicht

#### Isoliertes adaptives Routing
* Idee:
  * Routingentscheidungen werden nur anhand der Informationen des lokalen Routers getroffen, wie bei Hotpotato oder Rückwärtslernen
* Hot Potato Routing
  * Wenn ein Paket ankommt, so leite es auf schnellste Art und Weise an den Ausgang mit der kleinsten Ausgangswarteschlange, ganz egal wohin dieser Ausgang dann führt

##### Rückwärtslernen
* Idee:
  * Paketheader enthalten wichtige Infos, wie Quelle, Ziel, Hopzähler -> Netzwerkknoten lernen etwas über die Netzwerktopologie während sie Pakete behandeln
* Algorithmus:
  * Routing ursprünglich zufällig
  * Pakete mit Hopzähler 1 stammt von direkt verbundenem Knoten, usw…
  * Bei Ankunft eines Pakets vergleicht der IMP die Hopzahl für eine gegebene Quelladresse und aktualisiert diese falls nötig
  * Wichtig: Periodisches Vergessen der Routen ist wichtig, um sich weiterhin anpassen zu können

#### Verteiltes adaptives Routing
* Ziel: Finde einen guten Pfad durch das Netzwerk, welcher einen von der Quelle zum Ziel führt
* Graphabstraktion für Routingalgorithmen
  * Graphknoten sind Router
  * Graphkanten sind physische Links
    * Linkkosten: Verzögerung, € Kosten oder das Staulevel
    * Pfadkosten: Summe der Linkkosten auf einem Weg

#### Klassifikation von Algorithmen für dezentralisiertes adaptives Routing
Globale vs. dezentralisierte Information?
* Dezentralisiert
  * Router kennen physisch verbundene Nachbarn und Linkkosten zu diesen
  * Iterativer Prozess zum Berechnen und Austausch von Informationen mit Nachbarn
  * Distanzvektoralgorithmen:
    * RIP - Routing Information Protocol
    * BGP - Border Gateway Protocol
* Global
  * Alle Router haben vollständige Topologie- und Linkkosteninformationen
* Link State Algorithmen
  * Dijkstra
  * OSPF - Open Shortes Paths First

Statisch oder dynamisch?
* Statisch
  * Router wechseln langsam über die Zeit hinweg
* Dynamisch
  * Router wechseln häufiger
    * Periodisches Updaten als Antwort auf Linkkostenwechsel


### Distanzvektorrouting Algorithmen
* Iterativ
  * Läuft bis keine Knoten mehr Informationen austauschen
  * Selbstterminierend -> kein Stoppsignal
* Asynchron
  * Knoten müssen Informationen nicht getaktet austauschen
* Verteilt
  * Jeder Knoten kommuniziert nur mit seinem direkten Nachbarn
* Distanztabellendatenstruktur
  * Jeder Knoten hat seine eigene
    * Spalte für jedes mögliche Ziel
    * Zeile für jeden direkt angeschlossenen Nachbarknoten
  * Beispiel: in Knoten X, für Ziel Y über Nachbar Z:

> D^X(Y,Z) = Distanz von X nach Y mit Z als nächsten Hop

#### Distanzvektorrouting - Übersicht
* Iterativ, asynchron:
  * Jede lokale Änderung wird verursacht durch:
    * lokale Änderung der Linkkosten
    * Nachricht vom Nachbarn also dessen Änderung des kleinsten Knotenpfads
* Verteilt:
  * Jeder Knoten benachrichtigt die Nachbarn nur dann wenn sich dessen Pfad mit den kleinsten Kosten geändert hat

#### Distanzvektoralgorithmus - Quelltext
```
//Initialisierung: 
//für alle adjazenten Knoten v: 
D^X(*,v) = infinity
D^X(v,v) = c(X,v)
//für alle Ziele y
sende min-w D^X(y,w) an jeden Nachbarn
loop
wait (bis eine Veränderung der Linkkosten auffallen oder man benachrichtigt wird)
if(c(V,X) verändert)
  // verändere die Kosten zu allen Zielen durch den Nachbarn v durch d
  // d kann auch negativ sein 
  für alle Ziele y: D^X(y,V) = D^X(y,V)+d
else if(Empfang eines Updates von V w.r.t Ziel Y)
  // der kürzeste Pfad von Y zu einem Y hat sich verändert 
  // V hat einen neuen Wert für sein min-w D^V(Y,w)
  // rufe diesen neuen Wert newval ab
  für dieses einzelne Ziel y: D^X(y,V) = c(X,V)+newval
if (neues min-w D^X(Y,w) für irgendein Ziel Y, so senden wir den neuen Wert an alle Nachbarn)
forever
```

#### Distanzvektor: Reaktion auf Veränderung der Linkkosten
* Der Knoten erkennt die Veränderung von lokalen Linkkosten
* Die Distanztabelle wird geupdated
* Wenn Kosten im kleinsten Kostenpfad verändert werden, so werden die Nachbarn benachrichtigt
* Gute Nachrichten verbreiten sich schnell, schlechte Nachrichten verbreiten sich nur langsam

#### Poisoned Reverse
* Wenn Z durch Y routet um zu X zu gelangen:
  * Z sagt Y, dass seine eigene Distanz zu X unendlich ist (somit routet Y nicht über X nach Z)
  * Löst dies das gesamte Problems des Zählens bis in die Unendlichkeit?

### Link State Routing
* Linkstaterouting verwendet typischerweise Dijkstras Algorithmus
  * Netzwerktopologie und Linkkosten sind allen Knoten bekannt:
    * erzielt durch den Link-State-Broadcast
    * Alle Knoten mit selber Information
* Ziel: Berechnung des kleinsten Kostenpfades von einem Knoten S zu allen andern Knoten V:
  * Kann verwendet werden um eine Routingtabelle für dieses s zu erstellen

#### Dijkstrasalgorithmus zur Berechnung kürzester Pfade
* Grundlegende Idee:
  * Menge N mit Quellknoten S, füge nach und nach die zu dem Zeitpunkt bekannten mit kürzesten Pfaden erreichbaren Knoten ein
  * Initial werden alle Pfade zu anderen Knoten als S auf unendlich gesetzt
  * In jedem Schritt:
    * Wähle Knoten V, welcher nicht in N ist, und von S aus nur mit Pfaden über bereits entdeckte Knoten erreicht werden kann
    * Füge V in N ein
    * Aktualisiere die geschätzten Kosten für alle direkten Nachbarn w von v, falls ein Pfad über v billiger wäre als die bisherige Schätzung
    * Wenn eine Schätzung für einen Knoten w angepasst wird, so speichere auch den Vorgängerknoten V, welcher zu dieser Schätzung führt
* Somit speichert der Algorithmus für jeden Knoten v:
  * Einen Schätzwert für den kürzesten Pfad
  * Den Vorgängerknoten p(v) vom bis dahin als kürzesten Pfad angenommenen Pfad von s zu v
  * Eine Listen von Knoten N für welche die kürzesten Pfade definitiv bekannt sind
* Aktualisierungsverfahren für die Schätzwerte
  * Angenommen der Knoten v ist neu in die Liste hinzugefügt worden und wir aktualisieren den Schätzwert für den Knoten w:
  * d(v) ist der Schätzwert für den kürzesten Pfad von v, d(w) ist der Schätzwert für w
  * c(v,w) sind die Kosten der Kante von v zu w

```cpp
if( d(v) + c(v,w) < d(w)){
      d(w) = d(v) + c(v,w); 
      p(w) = v;
}
```

* Intuition hinter dieser Prozedur
  * Nimm an, dass d(w) und d(v) endlich sind
  * Es existiert also ein Pfad (s,v1,v2,…,v) von s zu v mit gewicht d(v)
  * Folglich existiert ein Pfad (s,v1,v2,…,v,w) von s zu w mit dem Gewicht d(v) + c(v,w)
  * Also gibt es einen weiteren Pfad mit Gewicht d(w)
  * somit kann der kürzeste Pfad zu w nicht mehr Gewicht haben, also entweder d(w) oder d(v)+c(v,w).

#### Weiterführende Diskussion zu Dijkstras Algorithmus
* Algorithmenkomplexität für |V| Knoten:
  * Jedes mal Überprüfung aller Knoten die nicht in N sind
  * Benötigt O(V²) Vergleiche, dies ist optimal in dicht besiedelten Graphen
  * Für dünnbesiedelte Graphen gibt es schnellere Varianten
* Variable Linkkosten -> Oszillation möglich

#### Link State Routing mit Dijkstras Algorithmus
* Jeder Router misst diie Kosten zwischen sich selbst und benachbarten Routern
* Der Router baut ein Paket, welches all diese Daten enthält
* Verteilung dieser Pakete durch Fluten mit Sequenznummern und einem Altersfeld, sodass bereits gesehene Pakete oder veraltete verworfen werden können
* Sobald ein Router alle Linkstatepakete erhalten hat, kann er die gesamte Topologie rekonstruieren und einen kürzesten Pfad zwischen sich und allen anderen Knoten berechnen

#### Vergleich zwischen Link-State und Distanzvektoralgorithmen
* Nachrichtenkomplexität:
  * LS: mit N Knoten und E Links werden O(n-e) Nachrichten versandt
  * DV: Austausch nur zwischen Nachbarn
* Konvergenzgeschwindigkeit
  * LS: O(n²) Algorithmus benötigt O(N-E) Nachrichten (teils mit Oszillation)
  * DV: Konvergenzzeit variiert
    * Routingschleifen, Count to Infinity Problem, Oszillation
* Robustheit: (im Falle eines Routerausfalls)
  * LS:
    * Ein Knoten kann falsche Linkkosten ausgeben
    * Jeder Knoten berechnet nur seine eigene Tabelle
  * DV:
    * DV Knoten kann falsche Gewichte ausgeben
    * Jede Tabelle wird nun noch von anderen Routern verwendet -> Fehler breiten sich über das ganze Netzwerk aus

### Hierarchisches Routing
Warum benötigen wir hierarchisches Routing?
* Skalierbarkeit -> 50+ Millionen Ziele in Routingtabellen ist sinnlos
* Autonomität -> Internet = Netz von Netzen, aber ein Admin möchte eventuell ja den Traffic im eigenen Netzwerk kontrollieren

#### Autonome Systeme
* Aggregation von Routern in Regionen -> Autonome Systeme AS
* Router im selben AS verwenden das selbe Routingprotokoll
  * Intra-AS Routingprotokoll

> Gateway Router:\
> * Spezielle Router innerhalb des AS, führen das Intra-AS Routingprotokoll mit allen anderen Routern im AS aus
> * Zusätzlich verantwortlich für das Routing an exteren Ziele -> Inter-AS Routingprotokolle mit anderen Gatewayroutern

#### Routing im Internet
* Das globale Internet besteht aus miteinander verbundenen AS
  * Stub AS: kleine Unternehmen (ein Link zum Internet)
  * Multihomed AS: große Unternehmen (mehrere Links, ohne Transitverkehr)
  * Transit AS: Netzbetreiber
* Zwei Level Routing:
  * Intra-AS: Administrator verantwortlich für die Auswahl
    * RIP: Distanzvektor
    * OSPF: Link State
    * IGRP: Distanzvektor
  * Inter-AS: Einheitlicher Standard
    * BGP: Pfadvektor

#### Verschiedenes Intra-AS und Inter-AS Routing, aber warum?
* Policy:
  * Inter AS: Admin möchte Kontrolle über sein Netz haben
  * Intra AS: ein einziger Admin, also keine Policyentscheidungen nötig
* Skalierbarkeit:
  * Hierarchisches Routing spart Tabellenplatz und sorgt für weniger Updateverkehr
* Performance:
  * Inter-AS: Policy wichtiger als Performance
  * Intra-AS: Performance als oberstes Gut

#### Verbundene autonome Systeme
* Forwardingtabelle sowohl durch intra- als auch inter-AS Routingalgorithmen konfiguriert
  * Intra-AS setzt Einträge für interne Ziele
  * Inter-As und Intra-AS setzt Einträge für externe Ziele

#### Inter-AS Aufgaben
* Problem
  * AS1 erhält Datagramm für ein Ziel außerhalb von AS1, Weiterleitung durch Gateway Router, aber welchen?
* AS1 muss lernen welche Ziele über AS2 und AS3 erreichbar sind und diese Info an alle Router in AS1 weitergeben
* -> Job des Inter-AS Routing

##### Beispiel: Setzen der Weiterleitungstabelle in Router 1d
* Angenommen AS1 lernt vom Inter-AS Protokoll, dass das Subnetz x durch AS3 (Gateway 1c) erreichbar ist, aber nicht von AS2
* Verteilung der Info an alle internen Router
* Router 1d bestimmt über die Intra-AS Routinginformation, dass sein Interface l auf dem Pfad mit den geringsten Kosten zu 1c ist
* Der Router setzt nun einen Eintrag in die Weiterleitungstabelle (x,l)

##### Beispiel: Wählen aus mehreren ASen
* Angenommen AS1, lernt durch das inter-AS Protokoll, dass es Subnetz x über AS2 und AS3 erreichen kann
* Um die Weiterleitungstabelle zu Konfigurieren muss Router 1d herausfinden, zu welchem Gateway es die Pakete für Subnetz x weiterleiten sollte -> Ebenfalls Job des Inter-AS Protokolls
* Hot-Potato-Routing: Sende das Paket an den nächsten von zwei Routern, werde das Paket also so schnell wie möglich wieder los

### Routing im Internet
#### Intra-AS Routing (IGP)
* Typische Routingprotokolle: RIP, OSPF, IGRP

#### RIP - Routing Information Protokoll
* Distanzvektoralgorithmus mit #Hops als Metrik

#### RIP - Advertisements
* Distanzvektoren:
  * Austausch zwischen Nachbarn alle 30s via Responsenachrichten
  * Auch Advertisements genannt
* Jedes Advertisement
  * Liste an bis zu 25 Zielnetzwerken im AS

#### RIP - Linkausfall und Linkrecovery
Falls nach 180s kein Advertisement empfangen wurde, so deklariere den Nachbarn als tot
* Routen werden invalid -> Nachbarn werden informiert und verbreiten die Informationen
* Verwenden poisoned reverse um ping-pong-loops zu verhindern (undendliche Distanz = 16 Hops)

#### RIP - Tabellenverarbeitung
* RIP Routingtabellen werden durch einen Prozess (route-d) auf Anwendungsebene gemanagt
* Advertisements werden periodisch in UDP Paketen verschickt

### OSPF - Open Shortest Path First
* Open = Öffentlich verfügbar
* Beruht auf dem Link-State-Algorithmus
  * LS Paketfluten
  * Topologiekarte an jedem Knoten verfügbar
  * Routenberechnung mit Dijkstra
* OSPF Advertisements annocieren nun keine Wege sondern Linkzustände mit je einem Eintrag pro Nachbarknoten
  * Fluten der Advertisements, welche direkt in IP Pakete eingebettet sind, in das gesamte Netzwerk

#### Weiterführende Funktionen
* Sicherheit: alle Nachrichten authentifiziert
* Mehrere Pfade mit gleichen Kosten erlaubt
* Für jeden Link gibt es mehrere Kostenmetriken für verschiedene Types of Service (TOS)
* Integrierter Support für Uni und Multicast
  > Unicast: Ein Sender, ein Empfänger
  >
  > Multicast: Ein Sender, eine Gruppe von Empfänger
  >
  > Broadcast: Ein Sender, alle Teilnehmer eines Netzes

#### Hierarchisches OSPF
* Zwei Level Hierarchie: local Area, backbone
  * Link State Advertisements nur im eigenen Gebiet
  * Jeder Knoten mit detaillierter Gebietstopologie, kennt aber nur die Richtung zu Netzwerken in anderen Gebieten
* Area Border Router: Fassen Distanzen zu Netzen im eigenen Gebiet zusammen, senden Adverisements an andere Area-Border-Router
* Backbone Router: führen OSPF uneingeschränkt auf Backbones aus
* Boundary Router: verbinden zu anderen ASs

#### BGP - Border Gateway Protokoll
* De facto Standard
* BGP stellt jedem autonomen System die Möglichkeit bereit:
  * Subnetzerreichbarkeitsinfos vom Nachbar AS zu erhalten
  * Erreichbarkeitsinformationen im gesaten AS zu verteilen
  * Gute Routen zu Subnetzen herauszufinden
  * Erlaubt es Subnetzen deren Existenz zu verkünden

#### BGP - Grundlagen
* Routerpaare tauschen Routinginformationen über semipermanente TCP Verbindungen aus: BGP Sitzungen (sind keine physischen Links)
* Wenn AS2 einen Prefix an AS1 verkündet, so ist dies ein Versprechen, alle an diesen Prefix adressierten Datagramme dorthin weiterzuleiten

#### Verteilung von Erreichbarkeitsinformationen
* Dank eBGP Sitzung zwischen 3a und 1c sendet AS3 eine Prefixerreichbarkeitsinformation an AS1
* 1c kann dann iBGP verwenden um diese neue Prefixerreichbarkeitsinformation an alle Router in AS1 verschicken
* 1b kann diese neue Erreichbarkeitsinformation an AS2 über die 1b zu 2a eBGP Sitzung weiter verteilen
* Wenn ein Router etwas über einen eneuen Prefix lernt, so erstellt er einen Eintrag für diesen Prefix in seiner eigenen Weiterleitungstabelle

#### Pfadattribute und BGP Routen
* Wenn ein Prefix verkündet wird, so enthält diese Verkündigung BGP Attribute:
  * Prefix + Attribute = Route
* Zwei wichtige Attribute
  * AS-Pfad: Erhält die AS,durch die welche die Verkündigung für den Prefix hindurchgegangen ist
  * NEXT-HOP: Indiziert den spezifischen internen AS Router, welcher sozusagen spezifiuiert, in welches AS man als nächsten Hop gehen sollte
* Wenn der Gatewayrouter eine Routenankündigung erhält, so verwendet er eine import policy zum Annehmen oder Ablehnen der Route

#### BGP Routenwahl
* Falls mehr als eine Route zum Prefix führt muss eine gewählt werden, bspw. durch Policyentscheidungen, kürzeste AS Pfade oder Hot-Potato-Routing, …

#### BGP Nachrichten
* BGP Nachrichten werden in TCP Nachrichten übertragen
  * OPEN: Öffnet TCP Verbindung zum Peer und authentifiziert den Sender
  * UPDATE: Kündigt neuen Pfad an oder verwirft den Alten
  * KEEPALIVE: Hält die Verbindung am Leben wenn keine Update-Nachrichten verschickt werden müssen, ebenfalls das ACK für die OPEN Anfrage
  * NOTIFICATION: Zeigt Fehler in vorheriger Nachricht an; wird auch zum Terminieren der Verbindung verwendet

## Zusammenfassung Kapitel 7
* Routing in großen Netzwerken benötigt nicht nur adäquate Routingalgorithmen für generelle Graphen, sondern auch eine angemessene, hierarchische Struktur für Netzwerke
* Die Netzwerkstruktur muss sich in der Adressierungsstruktur zeigen, da flache Adressen in einem vermeidbaren Overhead resultieren würden
* Verschiedene Metriken und Ziele müssen erreicht werden, insbesondere im Interdomainrouting, bei welchem Optimalität nur ein einzelner Aspekt ist

---
# Kapitel 8: Transport Layer
## Transportlayerdienste und Protokolle
* Stellen logische Kommunikation zwischen Anwendungsprozessen von verschiedenen Hosts bereit
  * Sendeseite: Segmentiert Anwendungsnachrichten und leitet diese Segmente an die Netzwerkschicht
  * Empfangsseite: Reassembliert Segmente in Nachrichten und leitet diese an die Anwendungsschicht weiter
* Als Transportprotokolle werden im Internet hauptsächlich TCP und UDP verwendet

## Transport vs. Netzwerklayer
* Netzwerklayer: logische Kommunikation zwischen zwei Hosts
* Transportlayer: logische Kommunikation zwischen zwei Prozessen

## Transportlayerprotokolle im Internet
* Zuverlässige, in Order Zustellung: TCP
  * Stau- & Flusskontrolle
  * Verbindungsaufbau
* Unzuverlässige, ungeordente Zustellung: UDP
  * Einfache Erweiterung des best Effort IP Ansatzes
* Nicht vorhanden sind: Verzögerungs- und Bandbreitengarantien

## Adressierung und Multiplexing
* Stelle mehrere SAPs bereit um mehrere Anwendungen zu Multiplexen
* Bspw: Portnummern
  * Dynamisch alloziert, aber teils vordefiniert für bekannte Dienste, Webserver Port 80, Port 25 für Mail

## Multiplexing und Demultiplexing
* Multiplexing auf Sendeseite:
  * Sammeln von Daten an mehreren Sockets, verpacken der Daten mit Header zum Demultiplexing
* Demultiplexing auf Empfangsseite:
  * Zustellen empfangener Segmente an den korrekten Socket

### Wie funktioniert Demultiplexing?
* Hosts verwenden IP-Adressen und Portnummern um Segmente an korrekte Sockets zuzustellen

### Verbindungsloses Demultiplexing
* Erstelle Sockets mit Portnummern
  * DatagramSocket mySocket1 = new DatagramSocket(9111);
  * DatagramSocket mySocket1 = new DatagramSocket(9222);
* UDP Sockets werden übber Zweiertupel aus Ziel IP und Ziel Port identifiziert

### Verbindungsorierntiertes Demultiplexing
* TCP Sockets werden durch ein Vierertupel aus Quell-IP, Quellport, ZielIP und Zielport identifiziert
* Der Emfpänger verwendet alle vier Werte um das Segment an den passenden Socket weiterzuleiten
* Pro Server gleichzeitig mehrere Sockets, eindeutig bestimmt durch das 4er Tupel
* Webserver haben verschiedene Sockets für jeden verbundenen Client
  * Nichtpersistentes HTML hat verschiedene Sockets für jede Anfrage

### Multithreaded-Webserver
* Behandelt jede Anfrage als einen neuen Thread, anstelle eines neuen Prozesses, dh. ein Prozess handelt mehrere simultane Verbindungen -> höhere Crashwahrscheinlichkeit

### Verbindungskontrolle
* Bei verbindungsorientierten Diensten gibt es drei Phasen der Verbindung:
  * Connect
  * Data
  * Disconnect
* Für jede Phase gibt es spezielle Dienstprimitive, wobei wir je nach Layer noch einen layerspezifischen Prefix an die Primitive hinzufügen
  * Transportlayer: T-Connect, T-Data, T-Disconnect

#### Aufbau der Transportverbindung
* bestätigendes Serviceprimitiv: T-Connect
* Primitive:
  * T-Connect.Request(Zieladr., Quelladr)
  * T-Connect.Indication(Zieladr., Quelladr.)
  * T-Connect.Response(Antwortadresse)
  * T-Connect.Confirmation(Antwortadresse)

#### Datentransferdienst
* Datentransferdienst: T-Data (bestätigungslos)
* Primitive:
  * T-Data.req(userdata)
  * T-Data.ind(userdata)

#### Verbindungsabbau
* bestätigungsloser Abbaudienst: T-Disconnect
* Verwendung:
  * Abrupter Abbau einer Verbindung (möglw. Verlust von TSDUs)
  * Ablehnen einer Verbindungsanfrage
* Primitive:
  * T-Disconnect.req(userdata)
  * T-Disconnect.ind(reason, userdata)
* Parameter:
  * Grund des Abbaus: z.B. unbekannt, Veranlasst durch anderen Nutzer, Fehlen von Ressourcen, Auftreten von Fehler, Unerreichbarkeit

#### Probleme während des Verbindungsaufbaus
* Verlust der CR (Connection Request) oder CC (Connection Confirm) TPDU
* Duplikate von TPDUs

##### Drei Wege Handshake
* Problematisch ist vor allem der Verlust der CC TPDU
* Lösung: Drei Wege Handshake während des Verbindungsaufbaus
  * Verbindung wird Aufgabaut, sobald beide Verbindungsaufbau TPDUs bestätigt wurden
  * Benötigt zusätzliches ACK (Acknowledgement) oder DT (Data)
* Neues Problem: Schützt noch nicht vor verspäteten Duplikaten
  * Problem: Wenn sowohl die Verbindungsanfrage CR, als auch die Verbindungsbestätigung CC dupliziert und verspätet sind, so hat der Empfänger wieder keine Möglichkeit herauszufinden ob dies eine neue oder alte Kopie ist
* Lösung: Der Sender muss eine Frage beantworten, welche der Empfänger fragt
  * Packe hierzu eine Sequenznummer in die CR, ACK, CC, DATA TPDUs
  * Muss durch die Gegenseite kopiert werden, und erlaubt den Verbindungsaufbau nur dann, wenn die korrekte Nummer bereit gestellt wird. Verwende Sequenznummern deshalb möglichst nicht schnell hintereinander erneut
* Neue Lösung funktioniert für Duplikate der CR und der CR + ACK

##### Verbindungsablehnung
* Ablehnung einer eingehenden CR mit einer DR oder Error TPDU
  * Gründe:
    * Ablehnung durch Transportdienstbenutzer
    * Nichterfüllbarkeit der Dienstanforderungen

##### Verbindungsabbbau
* Normaler Abbau
  * Kann den Verlust von nicht bestätigten Daten nach sich ziehen, TCP verhindert dies, indem alle gesendeten PDUs vor Beenden der Verbindung bestätigt werden müssen
  * Varianten:
    * implizit: Abbau der Netzwerklayerverbindung
    * explizit: Verbindungsfreigabe mit Disconnect-TPDUs
* Sobald ein Verbindungskontext aufgebaut ist, sollte es einfach sein, eine Verbindung wieder abzubauen
  * Ziel: Abbau der Verbindung erst dann, wenn beide Teilnehmer zugestimmt haben, nichts mehr sagen zu wollen und alles erhalten zu haben -> Praktisch ist dies unmöglich: Denn woher weiß man, dass der Andere weiß, dass man weiß, dass der Andere weiß …, dass alles volständig übertragen wurde? -> Problem der zwei Armeen

##### Verbindungsabbau in der Realität
* Problem der zwei Armeen ist dem des Verbindungsbbaus äquivalent
* Wenn eine Verbindung abgebaut wird, kann man aber größere Risiken in Kauf nehmen
* Typischerweise gelößt mit 3-Wege-Handshake: Sende DR, setze einen Timer, warte auf den DR des Teilnehmers und bestätige diesen
* Auch die drei Problemfälle von verlorenem ACK, Verlorene zweite DR + erneute Übertragung der ersten DR sowie verlorene zweite DR + verlorenes ACK werden gelöst.

---
### Flusskontrolle
#### Motivation: Kontrolle von Überlastsituationen
Typischweise sind ein Sender, Empfänger und das Netzwerk dazwischen in der Kommunikation involviert, um Überlastsituationen zu verhindern, muss die Menge an Daten den vorhandenen Kapazitäten der Systeme angepasst werden

#### Flaschenhälse auf der Empfängerseite
* Annahme: Das Netzwerk selbst ist kein Flaschenhals, es kann alle Pakete ausliefern
* Gründe für Flaschenhälse auf der Empfangsseite: verschiedene Performancecharakteristika oder mehrere Sender auf einen Empfänger
* Konsequenzen: Empfänger ist überfordert mit ankommenden Paketen, Puffer laufen über und Daten gehen verloren

#### Flusskontrolle
* Aufgabe: Schutz des Empfängers vor zu vielen ankommenden Paketen von der Sendeseite
* Bereitgestellt auf der:
  * Linklayerebene: um Überlastung von "forwarding Segmenten" zu verhindern
  * Höhere Layer: um Überlastung von Verbindungen zu verhindern
* Flusskontrolle auf dem Transportlayer ist komplizierter
  * Viele Verbindungen, benötigt dynamische Allokation von Pufferspeicher
  * Transportlayer PDUs mit schwankender Größe
  * Puffermöglichkeiten des Netzes fügen weitere Komplexität hinzu

#### Flusskontrolle - Pufferallokation
* Flusskontrolle abhängig von der Puffermöglichkeit
* Um ausstehdene Pakete zu unterstützen müssen diese entweder sofort und in korrekter Reihenfolge beim Empfänger ankommen, oder es muss genügend Puffer vorhanden sein
* Wie erreicht man Puffersicherheit?
  * Empfänger verlangsamt den Sender
  * Anforderung von Pufferspeicher durch den Sender
  * Mitteilung des Empfängers an den Sender, dass nur noch so viel Puffer verfügbar ist (bei Sliding Window einfach das Sendefenster anpassen)

#### Flusskontrolle durch Continue und Stop
* Einfachste Lösung: Sende Stopnachrichten wenn der Empfänger nicht schritthalten kann und Continue, sobald wieder Ressourcen vorhanden sind
* Beispiel: XON/XOFF: funktioniert aber nur bei Fullduplexverbindungen

#### Implizite Flusskontrolle
* Idee: Halte ACKs oder NACKs zurück, um den Sender zu verlangsamen, somit werden Fehlerkontrollmechanismen nun zur Flusskontrolle missbraucht werden
* Nachteil: Senderseitig keine Unterscheidung mehr möglich, ob Pakete verloren gingen, oder er verlangsamt werden soll, was in unnötigen Wiederholungsübertragungen resultiert

#### Kreditbasierte Flusskontrolle
* Der Empfänger gewährt dem Sender expliziten Kredit, sodass dieser meherere Pakete senden kann
* Ist der Kredit aufgebraucht, so muss der Sender warten, bis er wieder neuen zugeteilt bekommt
* Hierbei benötigen wir Fehlerkontrolle um auf verlorene Kreditnachrichten resultieren zu können
* Alternativ: absoluter Kredit oder Kreditfenster

#### Flusskontrolle - Permits und Acknowledgements
* Permits = Empfänger hat Pufferspeicher, sende also weiter
* Acknowledgements = Empfänger hat Anzahl X an Paketen empfangen
* Kombinierbar mit dynamisch wachsendem Pufferplatz beim Emfänger (Beispiel TCP)

---
### Staukontrolle
#### Warum benötigt man Staukontrolle?
Jedes Netzwerk kann nur eine gewisse Anzahl an Traffic pro Zeit transportieren, wenn nun mehr Traffic von den Quellen ausgeht, als das Netzwerk als nominelle Kapazität hat, so kommt es zu Staukollapsen und verlorenen Paketen

#### Gründe für Stau
1. Zwei Sender, zwei Empfänger, ein Router mit unendlich viel Pufferspeicher, keine erneuten Übertragungen
   * Große Verzögerung bei Stau
2. Ein Router mit endlich viel Pufferspeicher, Sender überträgt Pakete nur erneut, wenn sie tatsächlich verloren gehen
   * Immer λ-in = λ-out (goodput)
   * Kosten des Staus:
     * Mehrarbeit wegen der erneuten Übertragung für einen goodput
     * Unbenötigte erneute Übertragungen
3. Vier Sender, Multihoppfade, Timeout/Erneute Übertragungen
   * Wenn ein Paket verworfen wird oder verloren geht, so war jede Übertragungskapazität für dieses Paket verloren und verschwendet.

#### Zusammenfassung
* Staukontrolle ist essentiell, um Schneeballeffekte zu vermeiden
  * Sobald ein Netzwerk einmal überladen ist, wird es Pakete verlieren
  * Nach Erkennung von Paketverlusten durch ein zuverlässiges Transportprotokoll, werden Pakete erneut übertragen, was die Last abermals erhöht
  * -> Teufelskreislauf

#### Adaptiere die Senderate an die Netzwerkkapazität
* Die Senderate jeder Quelle muss an die aktuelle Kapazität des Netzwerks angepasst werden
* Staukontrolle ist ein globales Problem, da dies abhängig von allen Routern, Weiterleitungsdisziplinen, Lastinjektionenund so weiter ist.
* Flusskontrolle wiederum ist ein lokales Problem
  * Die Quelle darf das Ziel nicht überlasten, also sind nur Ziel und Quelle involviert

#### Wünschenswerte Eigenschaften von Staukontrolle
* Sollte dazu führen, dass möglichst viele Pakete mit kurzer Verzögerung zugestellt werden
* Alle Teilnehmer sollten einen gerechten Anteil der verfügbaren Kapzität erhalten, aber wie bewertet man Fairness und was sollte alles beachtet werden?

#### Designoptionen für Staukontrollmechanismen
* Open Loop: Designe das System von Beginn an so, dass es korrekt funktioniert und man keine Korrekturen zur Laufzeit vornehmen muss
* Closed Loop: Verwende Feedback, um zu erlauben, dass sich der Sender an die Situation anpasst
* Explizited Feedback: Die Stelle, an welcher der Stau auftritt informiert den Sender
* Implizites Feedback: der Sender extrahiert aus dem Netzwerkverhalten Informationen darüber, wie er sich verhalten sollte

#### Mögliche Aktionen
* Erhöhen der Kapzität -> teuer, kurzfristig nicht umsetzbar
* Reservierungen und Zugriffskontrolle - erlaube also keinen zusätzlichen Verkehr wenn das Netzwerk stark ausgelastet ist -> nur für schaltkreisbasierende Netzwerke verfügbar
* Reduzierung der Last in kleiner Granularität -> Bringe einzelne Quellen dazu ihre Last zu reduzieren, sodass nichts terminiert werden muss (benötigt Feedback vom Netz: closed loop)

#### Mögliche Aktionen - Taxonomie
* Router vs. Hostzentriert
  * Wo werden die Informationen erhoben, Entscheidungen getroffen und Aktionen veranlasst?
* Fenster vs. Ratenbasiert
  * Wie wird die erlaubte, ins Netz zu gebende Last definiert, durch
    * die Rate, also X Bytes die Sekunde, oder
    * durch ein Staufenster, als Menge von Sequenznummern von Bytes, welche versendet werden müssen, bevor weitere Permits benötigt werden

#### Routeraktionen - Verwerfen von Paketen
* Pufferplatz eines Routers ist voll und ein neues Paket kommt an, welches verwirft man, das neu ankommende oder eines aus der Warteschlange?
  * Für Medieninhalte sind neue wichtiger als alte Pakete

#### Verwerfen von Paketen - Implizites Feedback
* Das sendende Protokoll kann Verluste erkennen, in kabelgebundenen Netzwerken ist annehmbar, dass Paketverluste nur durch Stau entstehen -> Verlust von Paketen als klarer Hinweis auf Stau
* Bei Open Loop Systemen sollte es nie vorkommen, dass ein Paket an einer vollen Warteschlange ankommt

#### Vermeiden von vollen Warteschlangen - Proaktive Aktionen
* Wenn ein in einem Netzwerk Pakete an einer vollen Warteschlange ankommen, so steht es bereits relativ schlecht um das Netz -> Eingreifen bereits vor dieser Situation
* Reagiere sobald die Queue einen gewissen Staufaktor erreicht hat -> Der Router ist dann in einem Warnzustand

#### Choke Pakete
* Sobald ein Stau der Router einen Stau erkannt hat -> Sende Chokepakete
* Chokepakete sagen dem Ziel, dass es seine Senderate verringern soll
* Problem hierbei: Wie sinnvoll ist es, in ein sowieso schon volles Netzwerk noch weitere Pakete zu injezieren? Und wie lange dauert es eigentlich bis die Quelle vom Stau erfährt (BW\*Delay)?

#### Warnungsbits
Sobald ein Router feststellt, dass er von Stau betroffen ist, setzt er ein Warnbit in allen Paketen die er verschickt -> Da das Ziel das Warnungsbit in sein ACK Paket aufnimmt, erfährt die Quelle vom Stau und kann ihre Sendeleistung minimieren

#### Random Early Detection
* nutze verworfene Pakete als implizites Feedback, bereits bevor die Warteschlange voll ist, wirf also vorzeitig Pakete weg um Feedback zu geben
* Mit steigender Staubelastung am Router kann die Entwurfswahrscheinlichkeit erhöht werden

#### Was passiert aber, wenn Feedback empfangen wurde?
* Ratenbasierte Protokolle:
  * Reduzieren der Rate ist einfach, aber wann erhöht man wieder?
* Fensterbasierte Protokolle: Schrumpfe das Staufenster
  * Um welchen Faktor? Wie lässt man das Fenster überhaupt wachsen?

---
### Transportprotokolle im Internet
#### UDP - User Datagram Protocol
* Kein Schnickschnack, minimalistisches Internettransportprotokoll
* Best Effort Dienst -> UDP Segmente können verloren gehen, nicht reihenfolgegetreu zugestelllt werden
* Verbindungslos -> Kein Handshaking und unabhängige Behandlung der Pakete
* UDP wird oftmals für das Streamen von Multimediainhalten verwendet -> Tolerant gegenüber Verlusten und Ratenempfindlich (weiterhin für DNS und SNMP)
* Verlässliche Dienste unter UDP mit Zuverlässigkeit auf dem Applikationslayer

##### UDP Checksummen
* Ziel: erkenne im Übertragenen Segment
* Senderseite:
  * Behandle Segmentinhalte als Sequenz von 16-Bit Integern
  * Checksumme: Addition der Segmentinhalte (1-Komplement)
  * Platziere den Checksummenwert in das Checksummenfeld
* Empfängerseite:
  * Berechne Checksumme des empfangengen Segments
  * Prüfe ob der berechnete Wert gleich dem im Cheksummenfeld ist
    * Falls nein -> Fehler erkannt
    * Falls ja -> kein Fehler erkannt, dass keiner passiert ist, ist aber dadurch nicht gesagt

#### TCP - Transmission Control Protocol
* Punkt-zu-Punkt: Ein Sender, ein Empfänger
* Zuverlässiger, reihenfolgegetreuer Bytestrom -> keine Nachrichtengrenzen
* Pipelined: Staukontrolle und Flusskontrolle bestimmen die Fenstergröße
* Sende und Empfangspuffer
* Vollduplex Daten: Bidirektionaler Datenfluss
* Verbindungsorientiert: Handshaking initialisiert den Sender- und Empfängerzustand bevor Daten ausgetauscht werden
* Fluss und Staukontrolle: Kein Überfordernd des Empfängers oder des Netzwerkes

##### TCP - Sequenznummern und ACKs
* Sequenznummern: Bytestromnummer des ersten Bytes aus den Daten des Segments
* ACKs: Sequenznummer des nächsten von der anderen Seite erwarteten Bytes
* Die Frage wie man Pakete, welche nicht in Reihenfolge angekommen sind, behandeln soll, überlässt TCP dem Implementierer

##### TCP Round Trip Time und Timeouts
* Zuverlässsiger Datenverkehr benötigt eine Behandlung von Timeouts
* Frage: Wie setzt man einen TCP Timeoutwert?
  * Länger als die schwankende RTT, nicht zu kurz -> Unnötige Neuübertragungen, nicht zu lange -> langsame Reaktion auf Segmentverlust
* Frage: Wie kann man die RTT abschätzen?
  * SampleRTT: gemessene Zeit von der Übertragung eines Segments bis zum Erhalt der ACK Nachricht
  * Besser: Mittelung über mehrere SampleRTTs
  > EstimatedRTT = (1-a) · EstimatedRTT + a · SampleRTT
* Exponentiell gewichteter Durchschnitt, typisch für a: 0,125
* Setzen des Timeouts auf EstimatedRTT + Sicherheitsbereich
* Erste Einschätzung, wie groß die Abweichung des SampleRTT zum EstimatedRTT ist:
  * DevRTT = (1-ß) · DevRTT + ß · |SampleRTT - EstimatedRTT|
  * mit ß = 0,25
* Setzen das Timeoutintervall auf: EstimatedRTT + 4 · DevRTT

##### TCP Verbindungsaufbau
* TCP Verbindungen können aktiv oder passiv hergestellt werden:
  * Active: Anfragen einer TCP Verbindung mit speziellem, über IP und Portnummer, spezifizierten Transportdienstnutzer
  * Passiv: eine Anwendung informiert TCP, dass sie bereit ist eine eingehende Verbindung zu akzeptieren.
    * Es kann ein Socket spezifiziert werden, auf welchem die Verbindung erwartet wird, oder
    * jede Verbindung wird angenommen (unspecified passive open)
    * Egal wie die Verbindung zustandekommt, wird allerdings ein neuer Socket erstellt

##### Verbindungsidentifikation bei TCP
* TCP Verbindungen laufen zwischen Initiator und Responder, bzw. den Anwendungsprozessen welche auf den Systemen laufen
* Eine TCP Verbindung wird über ein Vierertupel identifiziert
  >(Quellport, Quell IP, Zielport, Ziel IP) 

##### TCP Verbindungsmanagement
* Drei Wege Handshake
  * Client sendet ein TCP SYN (SYN = 1, ACK = 0) an den Server -> spezifiziert initiale, nie benutzte Sequenznummer
  * Server erhält das SYN Paket und antwortet mit einem SYNACK (SYN = 1, ACK = 1) -> Server alloziert Puffer und spezifikation der initialen Sequenznummer des Servers
  * Der Client erhält das SYNACK und antwortet hierauf mit einem ACK (SYN = 0, ACK = 1), hier können nun erstmals Daten enthalten sein
* Terminieren einer Verbindung
  * Client sendet ein TCP FIN
  * Server empfängt das FIN, antwortet mit einem ACK und sendet ebenfalls ein FIN
  * Client erhält ein FIN Segment, antwortet darauf mit ACK und geht in timed Wait Zustand, antwortet auf alle FINs mit ACKs
  * Server erhält ein ACK, die Verbindung ist geschlossen

##### TCP Verbindung in drei Phasen
1. Verbindungsaufbau
   * 3-Wege Handshake
   * Aushandlung der Fenstergröße und der Sequenznummern
2. Datentransfer
   * Piggybacking von Acknowledgements
3. Verbindungsabbau
   * bestätigt
   * verhindert den Verlust von bereits gesendeten Daten

##### Zuverlässiger Datentransfer in TCP
* TCP erschafft einen zuverlässigen Datendienst oberhalb des unzuverlässigen IP Dienstes
* Eigenschaften:
  * Pipelining von Paketen
  * Kumulative ACKs
  * Verwendung eines einzigen Neuübertragungstimers
  * Auslösung von Neuübertragungen durch:
    * Timeoutevents
    * Duplizierte ACKs

##### TCP Senderevents
* Daten von der Anwendung empfangen:
  * Erstelle Segment mit einer Sequenznummer #
  * Sequenznummer = Bytestromnummer des ersten Datenbytes im Segment
  * Starte den Timer, falls bisher nicht geschehen
* Timeout:
  * Übertrage das, den Timeout auslösende Paket erneut und starte den Timer von vorne
* Empfang eines ACKs
  * Falls es zuvor unbestätigte Segmente gab, so aktualisiere was als bestätigt bekannt ist und starte den Timer erneut, sollte es noch ausstehende Segmente geben

##### TCP Sender (vereinfacht)
* SendBase-1: letztes kumulativ bestätigte Byte (SendBase ist das nächste erwartete Byte)
* Beispiel:
  * SendBase = 72, y = 73, der Empfänger will also 73+; y > SendBase, so, dass die neuen Daten bestätigt werden

```cpp
NextSeqSum = InitialSeqSum
SendBase = InitialSeqSum
loop(forever){
  switch(event)
  event: data received from application above, create TCP Segment with sequence number NextSeqSum
  if(timer not running){
    start timer
  }
  pass Segment to IP
  NextSeqSum = NextSeqSum + length(data)

  event: timer timout
  retransmit not yet acked segment with smallest sequence number
  start timer

  event: ACK received, with ACK field value of y 
  if(y > sendBase){
    SendBase = y
    if(there are currently not-yet-acknowledged segments){
      start timer
    }
  }
}
```

##### TCP ACK Generierung
* Ereignis beim Empfänger:
  * Ankunft eines Segments in Reihenfolge mit erwarteter Sequenznummer. Alle Daten bis zu dieser Sequenznummer sind bereits bestätigt
    * Verspätetes ACK, warte bis zu 500ms auf das nächste Paket. Falls kein Segment eintrifft, so sende die Bestätigung
  * Ankunft eines Pakets in richtiger Reihenfolge mit erwarteter Sequenznummer, für ein anderes Paket steht das ACK allerdings noch aus
    * Sende sofort eine einzelne kumulierte Bestätigung für beide Pakete
  * Ankunft eines out-of-order Seqments mit einer höheren als erwarteten Sequenznummer. Also erkennung einer Lücke
    * Sende sofort eine duplizierte Bestätigung, welche die Sequenznummer des nächsten erwarteten Bytes anzeigt
  * Ankunft eines Segments, welches eine Lücke teilweise oder vollständig füllt
    * Sende sofort eine Bestätigung, unter der Bedingung, dass das Segment am niedrigeren Ende der Lücke startet

##### Schnelle Neuübertragung
* Die Timeoutperiode ist oft relativ lang -> große Verzögerung, bis ein verlorenes Paket erneut gesendet wird
* Erkenne verlorene Segmente über die ACK Duplikate
  * Sender senden oftmals viele Pakete hintereinander, wenn Segmente verloren gehen, so wird es voraussichtlich viele ACKduplikate geben
* Wenn der Sender 3 ACKs für die selben Daten erhält, so nimmt er an, dass das Segment nach den besätigten Daten verloren ging -> Schnelle Neuübertragung noch bevor der Timer ausläuft

##### Algorithmus
```cpp
event: ACK recevied, with ACK Field value of y 
if(y > SendBase){
  SendBase = y; 
  if(there are currently not-yet-acked segments){
    start timer
  }
}
else {
  increment count of duplicate ACKs received for y 
  if(count of duplicate y ACKs = 3){
    resend segment with sequence number y
  }
}
```

### TCP Fluss- und Staukontrolle
#### Sende- und Empfangspuffer bei TCP
* Sender: Puffer um Fehlerkontrolle bereit zu stellen
* Empfänger: Zwischenspeichern von noch nicht abgerufenen, oder nicht reihenfolgegetreu angekommenen Paketen
  * Bemerkung: Alte TCP Versionen verwendeten GoBackN und verwarfen diese Pakete

#### TCP Flusskontrolle: Angebotenes Fenster
* Der Empfänger kann seine Empfangpufferkapazitäten verkünden
  * Verwendeter Pufferspeicher = (NextByteExpected-1)-LastByteRead
  * Maximal verfügbarer Puffer = MaxRcvdBuffer
  * Angebotener Pufferplatz = MaxRcvdBuffer - ((NextByteExpected-1)-LastByteRead)
* Erinnerung: Das angebotene Fenster beschränkt die Menge an Daten welche der Sender in das Netzwerk schickt (Sender stellt sicher, dass LastByteSend-LastByteAcked <= Advertised Window ist)

#### Nagles Algorithmus - Selbsttaktung und Fenster
* TCP Selbsttaktung: Ankunft eines ACKs ist ein Zeichen dafür, dass neue Daten auf das Netzwerk geschickt werden können
* Es wäre allerdings sinnlos, für kleine Größen, wie ein Byte, direkt nach dem ACK weiterzusenden (silly window syndrome)
* Nagles Algorithmus beschreibt wie viele Daten TCP Senden darf
  * Wenn eine Anwendung zu versendende Daten produziert
    * falls sowohl angebotene Daten und das angebotene Fenster >= MSS -> Sende ein volles Segment
    * andernfalls
      * falls unbestätigte Daten auf dem Weg sind, so puffere neue Daten bis das MSS voll ist,
      * andernfalls schicke die Daten sofort

#### Staukontrolle bei TCP
* Implizites Feedback durch verworfene Pakete
  * Annahme: Stau als Hauptgrund für verworfene Pakete
* Fensterbasierte Staukontrolle
  * TCP führt Buch über die Anzahl an Bytes die es noch in das Netzwerk injezieren darf, diese Fenstergröße kann wachsen oder schrumpfen
  * Der Sender beschränkt die Übertragung zusätzlich:
    * LastByteSend-LastByteAcked <= CongWin

##### TCP ACK/Selbsttaktung
Durch die ACKs kann der Sender darüber Aufschluss erhalten, wann die Pakete das Netzwerk verlassen -> Folglich dienen ACKs nicht nur als Bestätigung, sondern auch als Erlaubnis wieder die selbe Anzahl an Daten in das Netzwerk zu senden

##### Gute und schlechte Nachrichten
* Gute Nachricht: Ankunft eines ACKs
  * Dh. wir haben das Netzwerk bisher nicht überlastet, versuchen folglich das Staufenster noch ein bisschen zu vergrößern
* Schlechte Nachrichten: Kein ACK, ein Timeout tritt auf
  * Das Paket wurde verworfen, das Netzwerk ist überlastet, versuchen also das Staufenster zu verkleinern

##### Verkleinern des Staufensters
* Überlastete Fenster sind äußerst unpraktisch, greifen deshalb drastisch ein, und halbieren das Staufenster, sobald ein Timeout eintritt
* Falls ein Paket durch Übertragungsfehler und nicht durch Überlastung verloren geht, so wird dies durch TCP missinterpretiert und es reagiert über
  * Tritt in Kabelnetzwerken selten auf, führt aber zu Problemen bei Drahtlosnetzwerken

##### Vergrößern des Staufensters
Der Sender kann sich hier nicht sicher sein, ob tatsächlich noch Kapzitäten vorhanden sind, deshalb versuche, wenn alle Pakete, der in der letzten RTT gesendeten Pakete, angekommen sind, ein Paket mehr zu senden

##### Additives Erhöhen
* Wartet nicht auf eine volle RTT um zusätzliche Last hinzuzufügen, sondern verwendet dazu bereits einzelne ACKs
```cpp
Increment = MSS · (MSS / Congestion Window)
Congestion Window += Increment

Mit MSS als maximale Segmentgröße
```

##### AIMD - Sägezahnmuster der angebotenen TCP Last
* TCP verwendet AIMD, also additive increase, multiplicative decrease Taktik
* Es wird also kontinuierich auf zusätzliche Bandbreite geprüft und durch die Erhöhung der Bandbreitengrenze wird das Netzwerk regelmäßig die multiplikative Verringerung ausführen -> Sägezahnmuster

##### Schnelle initialisierung - Slow Start (historischer Name)
* Problem: Es dauert ewig, bis wir mit einem neuen Netzwerk überhaupt mittels additive increase an die Bandbreitengrenze kommen
* Idee Vergrößerung des Staufensters mittels Verdopplung nach jeder RTT oder Hinzufügen eines Pakets je ACK

##### Verlassen des Slowstarts
Sobald die Bandbreitengrenze erreicht ist, werden Paketverluste und Timeouts auftreten, TCP wechselt ab diesem Zeitpunkt wieder in den normalen Modus

##### Problematik der Paketbursts
* Ein Sender sendet sein volles Fenster, alle Pakete kommen an, ACKs gehen verloren und es kommt zu Timeouts die das Staufenster halbieren
* Ein Paket wird erneut übertragen, und es kommt ein kumulatives ACK für alle Pakete an, der Sender allerdings sendet nun in seinem halbierten Sendefenster nochmals die selben Daten -> ACK Taktung fehlt

###### Lösung: Auch hier Slow Start verwenden
* Verhindern solcher Paketbursts durch lineare Erhöhung des Staufensters
  * Setzen das Staufenster auf 1 und starten Slow Start
* Weiterhin haben wir nun grundlegende Informationen über die Netzwerkkapazität
  * Müssen auf den ersten Paketverlust warten, hier ist das halbierte Fenster eine gute Annahme
  * Wir können nun den Verlust von Paketen verhindern, wenn wir das vorherige Staufenster als Stauschwellenwert ansehen

#### Zusammenfassung TCP Staukontrolle
* Wenn das Sendefenster < Schwellenwert, dann ist der Sender in der Slow Start Phase und das Fenster wächst exponentiell
* Wenn das Staufenster > Schwellenwert, dann ist der Sender in der Stauvermeidungsphase und das Fenster wächst linear
* Wenn ein dreifach dupliziertes ACK auftritt, so wird der Schwellenwert auf Staufenster/2 und das Staufenster auf den Schwellenwert gesetzt
* Wenn ein Timeout auftritt, so wird der Schwellenwert auf Staufenster/2 und das Staufenster auf 1 MSS gesetzt
* Erweiterungen: Fast Retransmit, fast recovery
  * Ergreifen korrigierende Aktionen ohne auf ein Timeout warten zu müssen
  * Nötig für Netze mit großen Bandbreitenverzögerungen
* Verschiedene TCP Versionen: TCP Tahoe, TCP Reno, TCP Vegas
* Größte Quelle für Komplikationen: Die Dummheit des Netzwerks

#### TCP Performance
##### TCP Durchsatz
Der Durchschnittliche Durchsatz von TCP ist 0,75 · W/RTT

##### TCP Fairness
* Fairnessziel: Wenn K TCP Sitzugen des selben Flaschenhalses mit Bandbreite R durchschreiten müssen, so sollten alle eine durchschnittliche von R/K haben.
* TCP ist fair, da:
  * Eine additive Erhöhung eine Steigung von 1 ergibt, sobald sich der Durchsatz erhöht
  * Multiplikative Verringerung den Durchsatz proportional verringert

#### Fairness
###### Fairness und UDP
UDP wird für Multimediaanwendungen verwendet, da sie durch die Staukontrolle nicht gedrosselt werden wollen, wir senden also mit konstanter Rate und kümmern uns nicht um Verluste

###### Fariness und parallele TCP-Verbindungen
* Programme können mehrere TCP-Verbindungen zu einem Host aufbauen
* Beispiel: Linkrate R unterstützt 9 Verbindungen
  * Eine neue Anwendung fragt nach einer TCP Verbindung und erhält Rate R/10
  * Eine neue Anwendung fragt nach neun TCP Verbindungen und erhält Rate R/2

###### Verzögerungsmodellierung
* Wie lange dauert es, bis ein Objekt nach der Anfrage bei einem Webserver empfangen wird?
  * Ohne Stau nur abhängig vom Verbindungsaufbau, der Datenübertragungsverzögerung und Slow Start
* Bemerkungen:
  * Link L zwischen Client und Server mit Rate R, S = MSS, O = Objektgröße in Bits, keine Neuübertragungen
  * Fenstergröße:
    * Zuerst feste Größe, W Segmente
    * Dann dynamische Fenster und Slowstart

###### Festes Staufenster
1. WS/R > RTT + S/R: ACK für das erste Segment im Fenster kommt an, bevor einganzes Fenster an Daten verschickt wurde, erlaubt kontinuierliches Dauersenden
    ```
    delay = 2RTT + O/R
    ```
2. WS/R < RTT + S/R: Warte auf das ACK nachdem ein Sendefenster an Daten geschickt wurde
    ```
    delay = 2RTT + O/R + (K-1)[S/R + RTT - WS/R]
    ```

###### TCP Verzögerungsmodellierung: Slow Start
* Die Verzögerung für ein Objekt ist die folgende:
    ```
    Latenz = 2RTT + O/R + P[RTT+S/R]-((2^p)-1) · (S/R)
    ```
* Wobei P die Anzahl an Zeiten ist, in denen TCP beim Server in Bereitschaft ist:
    ```
    P = min{Q, K-1}
    ```
* wobei Q die Anzahl an Zeiten ist, in denen der Server in Bereitschaft ist, unter der Bedingung, dass die Objekte von unendlicher Größe wären
* und K die Anzahl an Fenstern ist, welche das Objekt belegt
* Mit den Verzögerungskomponenten:
  * 2RTT für Verbindungsaufbau und Anfrage
  * O/R um das Objekt zu Übertragen
  * Zeit die der Server durch Slowstart ruht

### Fallstudie HTTP Modellierung
* Eine Webseite besteht aus folgenden Teilen
  * 1 Basis HTML Seite von O Bits
  * M Bildern zu je O Bits
* Nichtpersistentes HTTP (eine Verbindung pro Objekt)
  * M+1 TCP Verbindungen in einer Reihe
  * Antwortzeit:
    * (M+1) · O/R + (M+1) · 2RTT + Idlezeiten
* Persistentes HTTP (eine Verbindung für alle Objekte)
  * 2RTT für die Anfrage und den Empfang der Basis HTML Datei
  * 1 RTT zum Anfordern der Bilder und deren Erhalt
  * Antwortzeit
    * (M+1) · O/R + 3RTT + Idlezeiten
* Nichtpersistentes HTML mit X parallelen Verbindungen
  * 1 TCP Verbindung für die Basisdatei
  * M/X parallele Verbindungen für die Bilder
  * Antwortzeit
    * (M+1) · O/R + (M/X +1) · 2RTT + Idlezeiten

#### HTTP Antwortzeiten
* Für kleine Bandbreiten wird die Verbindungs- und Antwortzeit durch die Übertragungszeit dominiert
  * Persistente Verbindungen zeigen nur geringfügige Verbesserungen gegenüber parallelen Verbindungen
* Bei größeren RTTs wird die Antwortzeit vom TCP - Aufbau und Slowstartverzögerungen dominiert
  * Persistente Verbindungen sind nun deutlich im Vorteil, insbesondere in Netzen mit großem Bandwithdelayprodukt

## Zusammenfassung Kapitel 8
* Prinzipien hinter Transportlayerdiensten
  * Adressierung, Mulitplexing, Demultiplexing
  * Verbindungskontrolle
  * Flusskontrolle
  * Staukontrolle
* Instantiierung und Implementierung im Internet
  * UDP
  * TCP
* Drei wichtige Protokollfunktionen sind bei TCP direkt in einem Sliding Window Protokoll implementiert:
  * Fehlerkontrolle: Durch Sequenznummern, ACKs und Neuübertragungen
  * Flusskontrolle: Durch Inspizieren von ACKs und Permits
  * Staukontrolle: Durch das Verlangsamen des Senders, wenn Pakete oder ACKs verloren gehen

# Kapitel 9: Internet Application Layer
## Erstellen einer Netzwerkanwendung
* Schreibe Programme, die:
  * auf verschiedenen Endsystemen laufen
  * über ein Netzwerk kommunizieren
* Keine Software wird explizit für das Kernnetzwerk geschrieben
  * Kernnetzgeräte arbeiten nicht auf der Anwendungsschicht
  * Dieses Design erlaubt extrem schnelle Anwendungsentwicklung

## Prinzipien von Netzwerkanwendungen: Architekturen
* Client-Server
* Peer-to-Peer
* Hybride aus Client-Server und Peer-to-Peer

### Client-Server Architektur
* Server
  * ständig eingeschaltet und mit permanenter IP-Adresse
  * Serverfarmen zur Skalierung
* Clients
  * Kommunizieren zeitweise mit dem Server
  * Können dynamische IP-Adressen haben
  * Kommunizieren nie direkt miteinander

### Peer-to-Peer Architketur
* Ohne ständig eingeschalteten Server
* Beliebige Endsysteme kommunizieren direkt miteinander, sind dabei zeitweise verbunden und haben wechselnde IP Adressen

### Hybride Client-Server und P2P
* Ursprüngliches Napster-Filesharing
  * Filetransfer über P2P, mit zentralisierter Dateisuche
* Instant Messaging
  * Chatten zwischen den Anwendern verwendet P2P
  * Anwesenheitserkennung und Lokalisierung ist zentralisiert

## Prozesskommunikation
* Prozesse: Programm welches auf einem Host ausgeführt wird
  * Zwei Prozesse welche auf einem Host laufen, verwenden Interprozesskommunikation um zu kommunizieren
  * Prozesse auf unterschiedlichen Hosts verwenden Nachrichtenaustausch
    * Clientprozess: Initiiert die Verbindung
    * Serverprozess: Wartet darauf kontaktiert zu werden
  * Bemerkung: Anwendungen, welche die P2P Architektur verwenden, haben Client und Server Prozesse

### Sockets
* Prozesse Senden und Empfangen Nachrichten an oder von ihrem Socket
* Application Programming Interface
  * Wahl des Transportprotokolls
  * Möglichkeit einige Parameter zu definieren

### Adressierung von Prozessen
* Prozesse die Nachrichten empfangen sollen, müssen einen Bezeichner haben
* Jeder Host hat eine einzigartige 32-Bit IP-Adresse sowie eine Portnummer, beides zusammen ist durch den Bezeichner dann beschrieben

## Durch das Anwendungsprotokoll festgelegte Eigenschaften
* Arten von ausgetauschten Nachrichten
* Syntax der Nachrichtenarten und Semantik der einzelnen Felder
* Regeln darüber, wann Prozesse, wie welche Nachrichten senden und darauf reagieren
* Offene vs. proprietäre Protokolle
  * Public-Domain Protokolle
    * offen für jeden Zugänglich, erlauben Interoperabilität
    * Beispiel: HTTP, FTP, SMTP
  * Proprietäre Protokolle
    * Definiert durch einen Vertreiber, meist keine öffentlichen Spezifikationen
    * Beispiel: KaZaA, Skype

### Welche Transportdienste werden von den Anwendungen benötigt?
* Datenverlust
  * Audio verkraftet einiges an Verlust
  * Datenaustausch oder Telnet benötigen einen 100% zuverlässigen Datenaustausch
* Zeitliches Verhalten
  * Internettelefonie oder Games brauchen kurze Latenzen
* Bandbreite
  * Multimediaanwendungen benötigen teils eine minimale Bandbreite um funktionieren zu können
  * Elastische Anwendungen hingegen, kommen mit so viel Bandbreite zurecht, wie sie eben zugesprochen bekommen

## Internettransportprotokolldienste
* TCP
  * Verbindungsorientiert -> Verbindungsaufbau zwischen Client und Server benötigt
  * zuverlässiger Transport
  * Flusskontrolle -> Der Sender überlastet den Empfänger nicht
  * Staukontrolle -> Verlangsame den Sender, wenn das Netzwerk nahe der Belastungsgrenze ist
  * Nicht vorhanden -> Timing, Garantien über die Bandbreite
* UDP
  * Unzuverlässiger Datentransfer
  * Nicht bereitgestellt
    * Verbindungsaufbau
    * Zuverlässigkeit
    * Fluss- und Staukontrolle
    * Timing oder Bandbreitengarantien

## Web & HTTP
* Eine Website beseht aus Objekten
* Objekte können ein Bild, eine HTML Datei, ein Java Applet sein
* Eine Webseite besteht aus einer grundlegenden HTML Datei, welche verschiedene Referenzen auf Objekte enthält
* Jedes Objekt ist durch eine URL adressierbar

### HTTP Übersicht
HTTP - Hyper Text Transfer Protocol
* Das Anwendungsnachrichtenprotokoll des Webs
* Client-Server Modell
* Wichtige Entwicklungsstufen:
  * HTTP 1.0 (schließt die Verbindung nach jeder Anfrage)
  * HTTP 1.1 (hält die Verbindung auch weiterhin Aufrecht)
* HTTP verwendet TCP
  * Clients bauen eine TCP Verbindung zum Server an Port 80 auf
  * Server akzeptieren diese Anfragen und HTTP Nachrichten werden zwischen dem Browser und dem Webserver ausgetauscht
  * Die TCP Verbindung wird geschlossen
* HTTP selbst ist zustandslos, d.h. der Server hält keine Informationen über frühere Besuche auf der Website

### HTTP Verbindungen
* Nichtpersistentes HTTP:
  * höchstens ein Objekt wird über die TCP Verbindung verschickt
  * HTTP/1.0 ist nichtpersistent
* Persistentes HTTP
  * Mehrere Objekte können über eine TCP Verbindung zwischen Client und Server ausgetauscht werden
  * HTTP/1.1 verwendet standardmäßig Persistenz

### Antwortzeitmodellierung
> RTT\
> Benötigte Zeit um ein kleines Paket so zu senden, dass es vom Client zum Server und zurück geschickt wird.

* Antwortzeit
  * eine RTT um die TCP Verbindung aufzubauen
  * eine RTT für die HTTP Anfrage und die ersten paar Bytes der Antwort
* Totalzeit
  * 2 RTT + Dateiübertragungszeit

### Persistentes HTTP
* Probleme nicht persistenten HTTPs
  * Benötigt 2RTT pro Objekt
  * Allokierung von Hostressourcen für jede TCP Verbindung
  * Browser können immerhin oftmals mehrere TCP Verbindungen aufbauen, um referenzierte Objekte zu Empfangen
* Persistentes HTTP
  * Der Server lässt die Verbindung auch nach der Antwort noch am Leben
  * Nachfolgende HTTP Nachrichten werden also über den selben, bereits allokierten Kanal gesendet
* Persistenz ohne Pipeling
  * Der Client stellt nur dann eine Anfrage, wenn die vorherige Antwort empfangen wurde
  * Eine RTT für jedes referenzierte Objekt
* Persistenz mit Pipelining
  * Standard in HTTP/1.1
  * Der Client sendet eine Anfrage, sobald er ein referenziertes Objekt entdeckt
  * Nur eine RTT für alle referenzierten Objekte

### HTTP Anfragenachrichten
Insgesamt nur zwei Arten von Nachrichten: request und response

![screenshot013.png](/core/preview?fileId=295415&x=1024&y=1024&a=true#mimetype=image%2Fpng&hasPreview=true&fileId=295415)

### Hochladen von Einfaben
* POST Methode
  * Webseiten beinhalten oft Formulareingaben, die Eingabe wird dann im Entity Body an den Server geschickt
* URL Methode
  * Verwendet die GET Methode
  * Die Eingaben werden im URL Feld der Requestline hochgeladen

### Methodentypen
* HTTP 1.0
  * GET
  * POST
  * HEAD (Anweisung, das angefragte Element in der Antwort außen vor zu lassen)
* HTTP 1.1
  * GET, POST, HEAD
  * PUT (Läd die Datei im Entity Body an den in der URL spezifizierten Pfad)
  * DELETE (Löscht die in der URL spezifizierte Datei)

### HTTP Statuscodes
* 200 OK - Anfrage okay, das angefragte Objekt folgt
* 301 Moved Permanently - das angefragte Objekt wurde verschoben, der neue Pfad folgt
* 400 Bad Request - Anfrage wurde nicht verstanden
* 404 Not Found - angefrodertes Objekt konnte auf dem Server nicht gefunden werden
* 505 HTTP Version not supported

### HTTP Webcaching und Cookies
#### Nutzer-Server-Zustand: Cookies
* Vier Komponenten
  * Cookieheaderzeile in der Antwort
  * Cookieheaderzeile in der Anfrage
  * Die Cookiedatei wird auf dem Rechner des Hosts gespeichert und vom Browser verwaltet
  * Speichern der Cookieinformationen in einer Backenddatenbank der Webseite
* Welchen Nutzen haben Cookies?
  * Autorisierung
  * Warenkörbe und Empfehlungen
  * Nutzersitungszustand

> Cookies erlauben es den Webseite viel über einen Nutzer herauszufinden,
man gibt beispielsweise unfreiwillig Namen und Emailadressen weiter,
welche zum Beispiel für Werbeagenturen gefundenes Fressen sind.  

#### Webcaches (Proxyserver)
Ziel: Bedienen der Clientanfrage ohne den urpsrünglichen Webserver dabei zu involvieren
* Der Nutzer stellt den Browser so ein, dass dieser über einen Cache auf das Netz zugreift
* Alle Anfragen des Browsers gehen zuerst an den Cache, hat er das angefragte Material, so wird er dieses an den Client schicken, oder andernfalls beim Webserver besorgen und dem Client dann weiterleiten

##### Weitere Informationen über Webcaches
* Der Cache agiert sowohl als Client als auch als Server
* Gründe für Webcaches
  * Reduzieren von Antwortzeiten für Clientanfragen
  * Reduzieren von Verkehr auf dem Zugangslink des ISPs
  * Ein Internet voller Caches erlaubt es armen Anbietern effektiv Inhalte zu übertragen

##### Bedingtes GET
* Ziel: Sende das Objekt nicht, wenn eine aktuelle Version des Objekts bereits im Cache liegt
* Cache: Spezifiziere das letzte Änderungsdatum der Datei im Cache in der HTTP Anfrage
* Server: Die Antwort beinhaltet das Objekt nur dann, wenn die Kopie im Cache veraltet ist

### Webserverarchitekturen
#### Grundlegende Webserveraufgaben
* Zum Empfang von Anfragen bereitmachen
* Annehmen von Verbindungen und Anfragen
* Lesen und Verarbeiten von Anfragen
* Antworten auf Anfragen
* Bereitmachen und Annehmen von Anfragen

#### Webserverarchitekturen
* Prozessmodell
* Threadmodell
* In-Kernel Modell
* Eventbasiertes Modell

##### 1. Prozessmodell
* Einem Prozess werden alle benötigten Schritte zugewiesen, welche benötigt werden, um eine Anfrage zu bearbeiten
* Wenn die Bearbeitung abgeschlossen ist, so ist der Prozess wieder in der Lage neue Verbindungen zu akzeptieren
* Typischerweise werden mehrere Prozesse benötigt
* Ein Prozess blockiert, beispielsweise read(), dann entscheidet das OS, welcher Prozess als nächstes ausgeführt werden darf
* Die Parallelität wird durch die Anzahl an Prozessen limitiert
* Beispiel: Apache auf UNIX
* Vorteile
  * Synchronisation dem Prozessmodell inhärent
  * Absicherung zwischen Prozessen
* Nachteile
  * Langsam
  * Schwere Ausführbarkeit von Operationen, welche auf globalen Informationen beruhen

##### 2. Threadmodell
Verwende Threads anstelle von Prozessen
* Motivation:
  * Threaderstellung und Threadlöschung ist billiger
  * Austausch von Daten zwischen Threads ist einfacher als bei Prozessen, aber Synchronisation wird nun für geteilte Daten benötigt
* Beispiele:
  * JAWS, IIS, Apache unter Windows
* Vorteile:
  * Schneller als Prozesse
  * Teilen standardmäßig aktiv
* Nachteile:
  * Benötigt OS Unterstützung
  * Kann per Prozess Limitierungen überlasten
  * Beschränkte Kontrolle über Schedulingentscheidungen

##### 3. In-Kernel Modell
* Eine Möglichkeit: ganzer Server im Kernel
* Meist: nur statische Dateien werden vom Kernel bedient, andere Anfragen gehen an den regulären User-Space-Server
* Dedizierter Kernelthread für HTTP Anfragen
* Vorteile:
  * Vermeidet das Kopieren von und in den Userspace
  * Sehr schnell, solange es eng in den Kernel integriert ist
* Nachteile:
  * Bugs können das OS, also die ganze Maschine crashen
  * Schwer zu debuggen und zu Erweitern
  * Inhärent OS-spezifisch
* Beispiele:
  * khttpd
  * TUX
  * AFPA (Advanced Fast Path Architecture)

##### 4. Eventbasiertes Modell
Verwenden eines einzelnen Webserverprozesses um mehrere Anfragen zu behandeln
* Beispiele: Zeus, Flash, Boa, Mathopd, ScatterWeb EWS
* Ein einzelnes HTTP Servermodell mit einer Liste an HTTP Verbindungen: list[index];
* myHttpConnection[index].status = {response, begin, end, dynamic}
* myHttpConnection[index].PosInPage = readpointer;
* Vorteile
  * Sehr schnell, kein Kontextwechsel
  * Inhärentes Teilen ohne Locks
  * Komplette Kontrolle über die Schedulingentscheidungen
  * Kein komplexer OS-Support benötigt
* Nachteile
  * Per-Prozess Begrenzungen
  * Nicht jedes OS mit voll asynchroner E/A, so können beim Lesen immernoch Blockierungen entstehen
  * Flash verwendet immerhin Hilfsprozesse um dies zu verhindern

#### Performancevergleich
###### Webservercluster
* Zwei Wege um die Kapazität zu erhöhen:
  * eine größere Maschine
  * Cluster an billigen Standardmaschinen, beispielsweise PCs
* Zur Zeit dominiert v.a. die zweite Variante aufgrund:
  * der Skalierbarkeit
  * der Hochverfügbarkeit
  * der Kosten
* Es stellt sich eine wichtige Designfrage: Anfragenverteilung
  * Traditionell: Round Robin
  * Effizienter: Inhaltsbasiert

#### FTP: Das Dateitransferprotokoll
* Übertrage Daten von und zum Server
* Client Server Modell
* Standard FTP Port: 21

##### Separate Kontroll- & Datenverbindung
* Der FTP Client kontaktiert den Server auf Port 21 und verwendet dazu das TCP Protokoll
* Der Client wird über eine Kontrollverbindung autorisiert
* Der Client kann nun auf dem entfernten Verzeichnis arbeiten, idem er Kommandos über die Kontrollleitung sendet
* Wenn ein Server ein Kommando zum Dateitransfer erhält, so öffnet er eine TCP Datenverbindung zum Client
* Nachdem eine Datei übertragen wurde, schließt der Server die Verbindung, im Falle von einer weiteren zu übertragenden Datei, eröffnet der Server eine zweite TCP Datenverbindung
* -> Out of Band Kontrolle
* FTP Server behalten den Zustand, also derzeitiges Verhältnis und frühere Authentifizierung

##### FTP Kommandos und Antworten
* Beispielkommandos:
  * gesendet als ASCII Text über die Kontrollleitung
  * USER username
  * PASS password
  * LIST gibt den Inhalt des aktuellen Verzeichnis aus
  * RETR filename holt die Datei
  * STOR filename speichert die Datei auf dem entfernten Host
* Beispielrückgabecodes:
  * Statuscode und Phrase (wie bei HTTP)
  * 331 Username OK. password required
  * 125 data connection already open: transfer starting
  * 425 can't open data connection
  * 452 Error writing File

#### Electronic Mail: E-Mail
* Bestehend aus drei Hauptkomponenten
  * Useragent
  * Mailserver
  * Einfaches Mailübertragungsprotokoll: SMTP
* Useragent
  * Erlaubt das Schreiben, Lesen und Bearbeiten von Nachrichten
  * Ein- und ausgehende Nachrichten werden auf einem Server gespeichert
* Mailserver
  * Die Mailbox beinhaltet eingehende Nachrichten, die Nachrichtenschlange die ausgehenden Nachrichten

##### SMTP
* Verwendet TCP um Nachrichten zuverlässig vom Client zum Server zu übertragen, verwendet Port 25
* Direkte Übertragung: vom Sender zum Empfänger
* Dreiphasige Übertragung
  * Handshaking
  * Übertragung der Nachrichten
  * Terminieren der Verbindung
* Kommando/Antwort Interaktion
  * Kommandos: ASCII Text
  * Antwort: Statuscode und Phrase
* Nachrichten müssen in 7 Bit ASCII kodiert sein
* SMTP verwendet persistente Verbindungen
* SMTP Server verwenden CRLF um das Ende einer Nachricht zu erkennen
  * Führt zu Problemen, wenn man versucht ohne Bitstuffing einen einzelnen . zu versenden

###### SMTP Vergleich mit HTTP

* Beide verwenden ASCII Statuscodesund Kommando/Antwort Interaktion
* HTTP:
  * PULL: Der Initiator fragt den Antwortenden nach den Inhalten welche er haben möchte
  * Jedes Objekt in eigener Antwortnachricht
* SMTP:
  * PUSH: Der Initiator sendet dies, welches er kommunizieren will an den Antwortenden
  * Mehrere Objekte werden in einer mehrteiligen Nachricht gesendet

##### Mailnachrichtenformat
* SMTP als Protokoll, um Nachrichten auszutauschen
* RFC 822 als Standard für das Textnachrichtenformat
* Headerzeilen, beispielsweise:
  * To:
  * From:
  * Subject:
* Body:
  * Die Nachricht, bestehend nur aus ASCII Zeichen

###### Nachrichtenformat: Multimediaerweiterungen
* MIME: Multimedia Mail Extensions
* Zusätzliche Zeilen im Nachrichtenheader deklarieren den MIME Inhaltstyp

##### Mailzugriffsprotokolle
* SMTP: Zustellen/Speichern auf dem Empfangsserver
* Mailzugriffsprotokoll: Anfordern vom Server
  * POP: Post Office Protocol
    * Autorisierung und Download
  * IMAP: Internet Mail Access Protocol
    * Mehr Features aber komplexer
    * Manipulation der serverseitig gespeicherten Nachrichten
  * HTTP: Yahoo Mail, Hotmail, etc.

##### POP3
* Autorisierungsphase
  * Clientkommandos:
    * user: Nutzernamen deklarieren
    * pass: Passwort übermitteln
  * Serverantworten
    * +OK
    * -ERR
* Transaktionsphase
  * Client
    * list: Listet die Nachrichtennummern auf
    * retr: Ruft die Nachrichten durch ihre Nummern ab
    * dele: Löscht die Nachricht
    * quit: Logout

##### POP3 und IMAP
* POP3
  * Das Beispiel nutzt den Download und Delete Modus
    * Bob kann die Emails also nicht nochmals lesen, wenn er den Client wechselt
  * Download und Keep:
    * Ermöglicht es Kopien von Nachrichten auf mehreren Clients zu haben
  * POP3 ist zustandlos über mehrere Sitzungen
* IMAP
  * Behält alle Nachrichten am Server
  * Erlaubt es Nachrichten geräteübergreifend in Ordnern zu organisieren
  * IMAP hält den Nutzerzustand über Sitzungsgrenzen hinweg

### DNS - Domain Name System
* Für Menschen gibt es viele verschiedene Bezeichner, für Internethosts und Router gibt es IP Adressen und Namen, doch wie kann man einen Namen auf eine IP-Adresse mappen?
* DNS
  * verteilte Datenbank implementiert in der Hierarchie von vielen verschiedenen Nameservern
  * Anwendungsschichtprotokoll für Hosts, Router und Nameserver zum Kommunizieren zur Namensauflösung
* DNS Dienste
  * Hostname auf IP Adressen Übersetzung
  * Host Aliasing
  * Mailserver
  * Lastverteilung mittels replizierter Webserver - Eine Menge von IP-Adressen für einen cannonical Namen
* Warum zentralisiert man DNS nicht?
  * Single Point of Failure
  * Verkehrsaufkommen, Instandhaltung und Wartung
  * Eine zentrale Autorität über die weltweite Namensauflösung?

-> Skaliert einfach viel zu schlecht

#### Verteilte hierarchische Datenbank
* Client möchte die IP für www.amazon.com
  * Rootserver wird nach dem .com Server gefragt
  * .com DNS Server wird nach dem amazon.com DNSServer gefragt
  * Der Client fragt den amazon.com DNS Server nach der IP für www.amazon.com

#### DNS: Root Name Server
* Kontaktiert von einem lokalen Nameserver, welcher den Namen nicht auflösen kann
* Root Name Server
  * Kontaktiert den autorativen Nameserver, falls das Namensmapping unbekannt ist, erhält das Mapping und leitet dies an den lokalen Nameserver zurück

#### TLD, Authorative und lokale DNS Server
* TLD (Top Level Domain) Server
  * Verantwortlich für .com, .org, .net, .edu und die Landesdomains
* Authorative DNS Server
  * DNS Server einer Organisation, stellen den authorativen Hostnamen für das IP Mapping der Organisationsserver
  * Verwaltung durch Organisation oder Dienstanbieter
* Lokale DNS Server
  * Gehören nicht strikt zur Hierarchie
  * Jeder ISP hat einen eigenen
  * Wenn ein Host eine DNS Anfrage stellt, so wird die Frage zuerst zum lokalen DNS Server gesendet (fungiert also als ein Proxy)

##### Iterative Anfragen
Der kontaktierte Server antwortet mit dem Namen des zu kontaktierenden Servers: "Ich kenne seinen Namen nicht, aber frage diesen Server und er wird dir helfen können"

##### Rekursive Anfragen
* Legt dem kontaktierten Server die Namensauflösung auf
* Aufgrund der hohen Last nicht durch TLD oder Rootserver unterstützt

#### DNS Caching und Updaten von Records
* Sobald ein Server ein Mapping kennenlernt, cacht er diese für eine bestimmte Zeit
  * TLD Server sind typischerweise in lokalen Nameservern gecacht, sodass nicht jedes mal der Rootserver besucht werden muss
* Update-/Benachrichtigungsmechanismen
  * Verwendet von DHCP Servern um DNS Einträge in den Servern aktuell zu halten
  * Alternativ auch DDNS über HTTPS um DNS Einträge für Hosts mit oft wechselnden IP Adressen zu aktualisieren

#### DNS Records
* DNS: Verteilte Datenbank, welche die Ressource Records (RR) speichert
    > RR Format: (name, value, type, ttl)
* Typ A
* name = Hostname
* value = IP Adresse
* Typ NS
  * name = die Domain
  * value = IP des authorativen Nameservers für diese Domain
* Typ MX
  * value ist der Name des Mailservers, welcher mit dem name assoziert ist
* Typ CNAME
  * name ist der Aliasname für irgendeinen cannonical Namen 
    * www.ibm.com ist tatsächlich servereast.backup2.ibm.com
  * value ist der cannonical Name

#### DNS Protokoll, Nachrichten
* DNS Protokoll: Frage und Antwortnachrichten mit selbem Nachrichtenformat
* Nachrichtenheader
  * Identfizierung - 16 Bit Nummer für die Frage, identisch für die Antwort
  * Flags
    * Frage oder Antwort
    * Rekursion erwünscht
    * Rekursion verfügbar
    * Antwort ist authorativ

##### Einfügen von Records ins DNS
* Registrieren den Namen bei einem Registrar
  * Müssen dem Registrar die Namen und IP Adressen von unserem authorativen Nameserver bereitstellen
  * Der Registrar fügt zwei RRs in den .com TLD Server:
    * (networkutopia.com, dns1.networkutopia.com, NS)
    * (dns1.networkutopia.com, 212.212.212.1, A)
  * Setzen dann einen Typ A Record für www.networkutopia.comund einen Typ MX Record für networkutopia.com in den authorativen Server

### P2P Filesharing
* Ausführung eines Filesharingclients auf dem eigenen Rechner, erhalten für jede Verbindung eine neue IP Adresse, suchen nach einer Datei, welche Alice von Bob kopieren will. Währenddessen können andere Leute schon bei Alice Dateien per HTTP kopieren
* Ein Peer ist sowohl ein Webclient als auch ein transienter Webserver
* Alle Peers sind Server -> Hoch Skalierbar

#### Probleme mit einem zentralisierten Verzeichnis
* Ein Single Point of Failure
* Performanceflaschenhals
* Copyrightverletzungen
> Dateiübertragung ist dezentralisiert, die Lokalisierung findet allerdings zentral statt. 

#### Anfragefluten: Gnutella
* Grundlegende Eigenschaften
  * komplett verteilt, also kein zentraler Server
  * Viele Gnutella Clients implementieren das Public Domain Protocol
* Overlaynetzwerk: Graph
  * Kante zwischen Peer X und Y, falls eine TCP Verbindung zwischen ihnen existiert
  * Alle aktiven Kanten und Knoten formen das Overlaynetzwerk
  * Eine Kante ist **kein** physischer Link

##### Gnutella Protokoll
* Fragenachricht wird über existierende TCP Verbindungen geschickt
* Peers leiten die Anfragenachricht weiter, Anfragentreffer werden dann rückwärts über den Pfad geschickt

##### Gnutella Peerjoining
* Ein neu hinzukommender Peer X muss andere Peers im Gnutellanetzwerk finden: verwende hierzu eine Liste an Peerkandidaten
* X versucht sequentiell Verbindungen mit Peers aufzubauen, bis X die Verbindung mit Y aufbaut
* X sendet eine Pingnachricht an Y, Y leitet diese weiter
* Alle Peers die dadurch eine Pingnachricht erhalten, senden eine Pongnachricht zurück
* X erhält nun viele Pongnachrichten. Hierauf kann X nun viele neue Verbindungen eingehen

### Socketprogrammierung mit TCP
Ziel: Lernen wie man Client/Server Anwendungen programmieren kann, welche Sockets zur kommunikation verwenden.
* Eingeführt in BSD 4.1 UNIX
* Sockets werden explizit erstellt, benutzt und durch Anwendungen freigegeben
* Client/Server Paradigmen
* Zwei Artenvon Transportdiensten über die Socket API:
  * Unzuverlässige Datagramme
  * Zuverlässig & Bytestromorientiert
> Socket\
> Ein lokal auf dem Host laufendes, von einer Anwendung erstelltes, OS-kontrolliertes Interface, durch welches ein Anwendungsprozess sowohl Nachrichten vom und zu anderen Anwendungsprozessen Senden, als auch Empfangen kann.

#### Socketprogrammierung unter Verwendung von TCP
* Socket: Tür zwischen Anwendungsprozess und dem Ende zu Ende Transportprotokoll
* TCP Dienst: zuverlässsige Übertragung von Bytes von einem Prozess zu einem anderen Prozess
* Der Client muss den Server kontaktieren
  * Der Serverprozess muss zuerst ausgeführt werden und einen Socket erstellt haben, welcher auf den Clientkontakt wartet
* Der Client kontaktiert den Server durch:
  * Erstellen eines lokalen TCP Sockets
  * Spezifizieren der IP-Adresse und der Portnummer des Serverprozess
  * Wenn der Client den Socket erstellt, dann baut das Client TCP eine Verbindung zum Server-TCP auf, das Server TCP erstellt daraufhin auch einen neuen Socket, sodass nun kommuniziert werden kann.
    * Dies erlaubt es dem Server mit mehreren Clients zu sprechen
    * Die Quellportnummern unterscheiden die Clients
  > Sichtweise der Anwendung\
  > TCP stellt eine zuverlässige und reihenfolgegetreue Übertragung von Bytes zwischen Client und Server sicher 

#### Stream Jargon
* Ein Stream ist eine Sequenz aus Zeichen, welche in oder aus einem Prozess fließen
* Ein Eingangsstream ist an eine Eingabequelle gebunden, beispielsweise eine Tastatur oder einen Socket
* Ein Ausgangsstream ist an eine Ausgabequelle gebunden, wie einen Monitor oder einen Socket

### Socketprogrammierung mit UDP
Bei UDP: Keine Verbindung zwischen Client und Server
* Kein Handshaking
* Der Sender fügt die IP-Adresse und den Zielport des Ziels explizit an jedes Paket
* Der Server muss die IP-Adresse und den Port des Senders aus dem erhaltenen Paket extrahieren
* Bei UDP können Daten nicht reihenfolgegetreu ankommen, oder verloren gehen
> Sichtweise der Anwendung\
> UDP stellt eine unzuverlässige Übertragung von Gruppen an Bytes zwischen Client und Server bereit

### Bauen eines einfachen Webservers
* Behandelt eine HTTP Anfrage, akzeptiert diese und parst den Header
* Zieht die angeforderte Datei vom Serverdateisystem
* Erstellt eine HTTP Antwortnachricht: Headerzeilen + Datei
* Sendet die Antwort an den Client

## Zusammenfassung Kapitel 9
* Anwendungsarchitekturen
  * Client/Server
  * Peer2Peer
  * Hybride
* Anforderungen an Anwendungsdienste
  * Zuverlässigkeit, Bandbreite, Verzögerung
* Internettransportdienstmodelle
  * Verbindungsorientiert, verlässlich: TCP
  * Unzuverlässig, mit Datagrammen: UDP
* Spezifische Protokolle
  * HTTP
  * FTP
  * SMTP, POP, IMAP
  * DNS
* Socketprogrammierung
* **Das wichtigste: Anwendungsprotokolle**
  * Typischerweise Anfrage/Antwort Nachrichtenaustausch
    * Clients fragen Info oder Dienst an
    * Server antworten mit Daten und Statuscode
  * Nachrichtenformate
  * Header: Felder welche Info über die Daten geben
  * Daten: Informationen, welche kommuniziert werden
  * Kontroll vs. Datennachrichten
    * In-Band vs. Out-of-Band
  * Zentralisiert vs. Dezentralisiert
  * Zuverlässiger vs. unzuverlässiger Nachrichtenaustausch
  * Komplexität am Rande des Netzwerks

---
# Kapitel 10: Netzwerk Sicherheit
## Einführung - Bedrohungen, Sicherheitsziele, Schutzmaßnahmen
### Was ist eine Bedrohung in einem Kommunikationsnetzwerk?
* Abstrakte Definition
  * Eine Bedrohung in einem Kommunikationsnetzwerk ist jedes mögliche Ereignis oder eine Sequenz von Aktionen, welche zu einer Verletzung einer oder mehrerer Sicherheitsziele führen
  * Die Realisierung einer Bedrohung wird Attacke genannt
* Beispiele:
  * Hacker brechen in Computer ein, Emails werden verändert, Finanzdaten werden verändert, ein Hacker legt eine Webseite lahm
* Was sind Sicherheitsziele:
  * Sicherheitsziele können definiert werden:
    * Abhängig vom Anwendungsumfeld, oder einem generelleren, technischeren Weg

#### Sicherheitsziele (Security Objectives) in Abnhängigkeit von der Anwendungsumgebung
* Banking
  * Schutz gegen Betrüger oder versehentliche Veränderung an Transaktionen
  * Eindeutiges und fälschungssicheres Identifizieren der Kunden
  * Sichern der PINs gegen zufälllige Entdeckung und der Privatspäre der Kunden
* Elektronisches Handeln
  * Schützen der Privatsphäre der Kunden und des Unternehmens
  * Bereitstellen von rechtlich bindenden Signaturen für Transaktionen
* und viele weitere im Bereich der Regierung, öffentlicher Telekommunikationsanbieter, Geschäfte und privater Haushalte
* Ziel ist es in jedem Fall sich gegen Angriffe von Außen zu schützen

#### Sicherheitsziele technisch definiert
* Vertraulichkeit:
  * Verschickte oder gespeicherte Daten sollen nur einem bestimmten Nutzerkreis zugänglich sein
  * Vertraulichkeit von Instanzen wird auch als Anonymität bezeichnet
* Datenintegrität
  * Es sollte möglich sein, jede Veränderung von Daten zu erkennen, dies benötigt unter anderem, die Möglichkeit den Ersteller von Daten identifizieren zu können
* Verantwortlichkeit
  * Es sollte möglich sein, eine Instanz zu identifizieren, welche für irgendein Kommunikationsereignis zuständig ist
* Verfügbarkeit
  * Dienste sollten verfügbar sein und auch funktionieren
* Kontrollierter Zugriff
  * Nur autorisierte Instanzen solle in der Lage sein auf bestimmte Dienste oder Daten zuzugreifen

#### Bedrohungen technisch definiert
* Maskerade (Spoofing)
  * Eine Instanz behauptet jemand Anderes zu sein
* Abhören (Sniffing)
  * Jemand versucht Daten zu lesen, welche er nicht lesen darf und soll
* Autorisierungsverletzungen
  * Eine Instanz verwendet Ressourcen die sie nicht verwenden darf
* Verlust oder Veränderung von übertragener Information
  * Veränderung oder Zerstörung von Daten
* Fälschung von Daten
  * Eine Instanz erzeugt Daten im Namen einer Anderen
* Abstreiten von Kommunikationsereignissen (Repudiation)
  * Eine Instanz streitet seine Beteiligung an einem Kommunikationsereignis ab
* Sabotage
  * Jede Art von Aktion welche darauf abzielt, die Verfügbarkeit oder korrekte Funktion von Diensten zu reduzieren

#### Sicherheitsanalyse von gelayerten Protokollarchitekturen
* Dimension 1: Auf welchem Interface findet der Angriff statt?
* Dimension 2: Auf welchem Layer findet der Angriff statt?

##### Angriff auf dem Nachrichtenlevel
* Passive Übergriffe:
  * Spähen
* Aktive Angriffe:
  * Verzögerung von PDUs
  * Wiederholung von PDUs
  * Löschen von PDUs
  * Veränderung von PDUs
  * Einfügen von PDUs
* Ein erfolgreicher Angriff benötigt:
  * Seiteneffektsfreiheit auf andere Kommunikationen
  * Steineneffektsfreiheit auf andere PDUs in der selben Datenübertragung
* Eine Sicherheitsanalyse einer Protokollarchitektur muss diese Angriffe bezüglich der Layer der Architektur analysieren

##### Sicherheitsmechanismen gegen Bedrohungen
* Physische Sicherheit:
  * Abschließen der Betriebsräume, Zutrittskontrolle
  * Tamper Proofing von sensitivem Equipment
  * Schutz vor Überwachung der Umgebung
* Personelle Sicherheit
  * Sensitivität bei Mitarbeitern erzeugen
  * Überprüfung der Angestellten
  * Sicherheitstraining
* Administrative Sicherheit
  * Kontrollieren neuer Software
  * Prozeduren um Sicherheitsverstöße zu erkennen
  * Ansehen und Reagieren auf Audittrails
* Ausstrahlungssicherheit
  * Steuerung von Frequenzen und anderer elektromagnetischer Ausstrahlungen
* Mediensicherheit
  * Kontrollieren der Erstellung, Reproduktion und Zerstörung von Informationen
  * Scannen von Medien auf Schadsoftware
* Lifecyclekontrollen
  * Vertrauenswürdiges Systemdesign der Implementierung, Evaluation und Unterstüzung
  * Dokumentierung
  * Einhalten von Programmierstandards
* Computersicherheit
  * Schutz der Informationen, während diese auf Rechnern gespeichert oder verarbeitet werden
  * Schutz der Rechner selbst
* Kommunikationssicherheit
  * Schutz der Informationen beim Transport von einem zum anderen System
  * Schutz der Kommunikationsinfrastruktur an sich

## Grundlagen der Sicherheitstechnologie
### Terminologie
* Sicherheitsdienst:
  * Abstrakter Dienst, welcher versucht, eine bestimmte Sicherheitseigenschaft zu gewährleisten
  * Kann mittels kryptographischer Algorithmen oder auf konventionelle Weise realisiert werden
* Kryptographischer Algorithmus
  * Eine mathematische Transformation von Eingangsdaten (Daten, Schlüsseln) zu Ausgangsdaten
* Kryptographisches Protokoll
  * Eine Serie an Schritten und Nachrichtenaustauschen zwischen mehreren Instanzen, um ein spezifisches Sicherheitsziel zu erfüllen

### Sicherheitsdienste - Übersicht
* Authentisierung
  * Grundlegender Sicherheitsdienst, welcher sicherstellt, dass eine Instanz tatsächlich die Identität hat, welche sie vorgibt zu haben
* Integrität
  * Kleiner Bruder der Authentisierung, da er sicherstellt, dass Daten, welche von einer gewissen Einheit erstellt worden sind, nicht ohne Erkennung verändert werden können
* Vertraulichkeit
  * Stellt sicher, dass die geschützen Daten geheim bleiben
* Zugriffskontrolle
  * Kontrolliert, dass jede Identität nur auf die Informationen und Dienste zugreift, zu welchen sie auch zugriffsberechtigt ist
* Nicht Ablehnung
  * Schütz davor, dass andere Einheiten nach einer Kommunikation behaupten können, nie daran teilgenommen zu haben

### Kryptologie - Definition und Terminologie
* Kryptologie:
  * Wissenschaft, die sich mit Kommunikation in sicherer und geheimer Art befasst
  * Kryptologie besteht aus
    * Kryptographie (graphein = schreiben): Die Lehre der Prinzipien und Techniken, durch welche Informationen in Ciphertext verpackt und später durch legitimierte Nutzer, wieder durch einen geheimen Schlüssel entschlüsselt werden können
    * Kryptoanalyse (analyein = etwas lösen): Die Wissenschaft und Kunst Informationen von Ciphern wiederherzustellen und dies ohne das Wissen über den Schlüssel zu schaffen
* Cipher:
  * Methode eine Nachricht so zu transformieren, dass die Bedeutung nicht mehr erkannt werden kann
  * Cipher sind nur eine Klasse kryptographischer Algorithmen
  * Die Transformation hat typischerweise eine Nachricht und einen geheimen Schlüssel als Eingabe

#### Kryptographische Algorithmen
* Für die Netzwerksicherheit sind vor allem das Verschlüsseln und Signieren von Daten von Bedeutung:
  * Verschlüsseln von Daten: Transformiert Plaintext in Ciphertext um die Inhalte zu verschleiern
  * Signieren von Daten: Berechnet einen Checkwert oder eine digitale Signatur zu einem gegebenen Plaintext oder Ciphertext, sodass dieser durch alle oder einige Instanzen mit Zugriff verifiziert werden kann
* Prinzipielle Kategorien von Kryptographiealgorithmen
  * Symmetrische Kryptographie verwendet einen Schlüssel für Ver- und Entschlüsselung oder Signieren und Überprüfen
  * Assymmetrische Kryptographie verwendet zwei Schlüssel für Ver- und Entschlüsselung
  * Kryptographische Hashfunktionen verwenden keinen Schlüssel (ist kein separater Input, wird in die Daten gemischt oder angehängt)

#### Wichtige Eigenschaften von Verschlüsselungsalgorithmen
* Fehlerausbreitung: Charakterisiert die Effekte von Bitfehlern während der Übertragung von Ciphertext zum rekonstruierten Klartext
* Synchronisation: Charakterisiert die Effekte von verlorenen Ciphertexten auf den rekonstruierten Klartext

##### Symmetrische Verschlüsselung
* Der selbe Schlüssel wird zur Ver- und Entschlüsselung eingesetzt
* Beispiele: DES, 3DES, AES, IDEA, RC4,…

##### Asymmetrische Kryptographie
* Idee:
  * Verwende zwei verschiedene Schlüssel +K und -K für Ver- und Entschlüsselung
  * Gegeben ein zufälliger Ciphertext c = E(+K,m) und +K, so sollte es unmöglich sein, m = D(-K,c) zu berechnen
  * Der Schlüssel -K ist nur A selbst bekannt und wird As privater Schlüssel genannt
  * Der Schlüssel +K ist As öffentlicher Schlüssel, den jeder kennen darf
* Anwendungen:
  * Verschlüsselung
    * Wenn B eine Nachricht mit As öffentlichem Schlüssel +K verschlüsselt, so kann sich B sicher sein, dass nur A diese Nachricht mit dem Schlüssel -K entschlüsseln kann
  * Signieren
    * Wenn A eine Nachricht mit seinem privaten Key -K verschlüsselt, so kann jeder diese Signatur mit As öffentlichem Schlüssel +K entschlüsseln
* Praktische Überlegungen
  * Asymmetrische Verschlüsselungsverfahren sind um Größenordnungen langsamer als symmetrische Verschlüsselung, deshalb verwendet man die asymmetrische Verschlüsselung eher in Verbindung mit symmetrischer, nämlich indem man die Datenmengen symmetrisch verschlüsselt, und nur den Schlüssel auf asymmetrische Art verschlüsselt

##### Erkennung verschlüsselter Nachrichten
* Motivation
  * Fehlererkennungscodes erlauben es uns zu erkennen, ob Nachrichten während der Übertragung durch Bitflips o.ä. verändert wurden (Parität, CRC, …)
  * -> Wunsch nach ähnlichem Wert, welcher besagt, ob eine Nachricht mutwillig verändert wurde
* Realisierung von MCVs:
  * Kryptographische Hashfunktionen
    * Entweder kombiniert mit asymmetrischer Kryptographie um einen signierten modification detection code (MDC) zu erhalten, oder Inklusion eines geteilten, geheimen, mit der Nachricht gemischten Schlüssel in der Nachricht
  * Message Authentication Codes
    * Häufige message authentication codes (MAC) werden aus einem symmetrischen Blockcipher konstruiert

##### Kryptographisches Protokoll
* Definition: Ein kryptographisches Protokoll wird definiert als eine Serie von Schritten und Nachrichtenaustauschen zwischen mehreren Einheiten um ein spezielles Sicherheitsziel zu erreichen
* Anwendungen kryptographischer Protokolle
  * Schlüsselaustausch
  * Authentisierung
    * Integrität: Erlaubt dem Empfänger zu verifizieren, von wem eine Nachricht kam und ob sie verändert wurde
    * Einheitenauthentisierung: Erlaubt es Kommunikationspartnern die Identität ihrer Peers zu verifizieren

## Einführung in die Sicherheitsdienste von Kommunikationsnetzwerken
### Sicherheit in Netzwerken: Was sollen wir wo tun?
* Dimension 1: Welcher Sicherheitsdienst auf welchem Knoten?
* Dimension 2: Welcher Sicherheitsdienst auf welcher Netzwerkebene?

### Pragmatisches Modelll für sicheres und vernetztes Rechnen
* Anwendung:
  * Ein Stück Software muss eine gewisse Aufgabe ausführen, beispielsweise Email, Webdienste, Speichern von Daten, …
* Endsystem:
  * Irgendein Gerät, von PC bis Server oder Mainframe
  * Endsysteme haben aus Sicherheitsgründen typischerweise eine Richtlinienautorität
* Subnetzwerk:
  * Sammlung von Kommunikationsstellen unter der Kontrolle einer administrativen Organisation
  * Aus Sicherheitsgründen haben Subnetz typischerweise eine Richtlinienautorität
* Inter-Netzwerk:
  * Sammlung von untereinander verbundener Subnetzwerken
  * Grundsätzlich haben in einem Inter-Netzwerk verbundene Subnetze eigene, also verschiedene Richtlinienautoritäten
* Vier Ebenen mit jeweils unterschiedichen Anforderungen an Sicherheitsprotokollelemente
  * Anwendungsebene: Sicherheitsptrotokollelemente sind anwendungsabhängig
  * Endsystemebene: Bereitstellung von Schutz auf einer Endsystem zu Endsystembasis
  * Subnetzwerkebene: Bereitstellung von Schutz über ein Subnetzwerk oder Inter-Netzwerk welches als weniger sicher als andere Stellen des Netzwerks gilt
  * Linkebene: Bereitstellung von Schutz in einem Subnetzwerk, beispielsweise über einen Link, welcher weniger vertrauenswürdig als andere Stellen des Subnetzwerks gilt

### Beziehungen zwischen Layern und Anforderungsleveln
* Die Beziehungen zwischen Protokolllayern und den Protokollelementssicherheitsanforderungen lassen sich nicht 1zu1 abbilden:
  * Sicherheitsmechanismen welche sowohl Anforderungen an Endsystemen oder Subnetzwerkebenen erfüllen, können entweder in der Transport, und/oder in der Netzwerkschicht realisiert werden
  * Link-Level-Anforderungen können erfüllt werden, indem man Sicherheitsmechanismen entweder im Linklayer, und/oder auf der physischen Ebene integriert

### Die IP Sicherheitsarchitektur IPSec
#### Sicherheitsprobleme des Internetprotokolls
* Wenn eine Instanz ein IP Paket erhält, so hat es keinen Nachweis über: 
  * Die Herkunft der Daten und deren Integrität
    * Also, dass das Paket tatsächlich von der Einheit gesendet wurde, welche in der Quelladresse des Pakets referenziert wird
    * dass das Paket noch den ursprünglichen Inhalt enthält 
    * dass die Empfangseinheit tatsächlich die Einheit ist, an welche der Sender das Paket schicken wollte
  * Vertraulichkeit
    * Dass die ursprünglichen Daten nicht von einem Dritten inspiziert und gelesen wurden, während das Paket auf dem Weg vom Sender zum Empfänger war 

#### Sicherheitsziele von IPSec
* Datenherkunftsauthentisierung/ Verbindungslose Datenintegrität: 
  * Es soll unmöglich sein, ein IP Datagramm mit einer maskierten Quell- oder Zieladresse zu versenden, ohne, dass dies der Emfpänger erkennen kann. 
  * Es soll unmöglich sein, ein IP Paket während der Übertragung so zu verändern, dass es dem Empfänger nicht auffallen kann
  * Wiederholungsschutz: Es soll nicht möglich sein, ein gespeichertes Paket zu späterem Zeitpunkt zu versenden, ohne, dass dies der Empfänger mitbekommt
* Vertrauenswürdigkeit: 
  * Es soll nicht möglich sein, den Inhalt der IP Datagramme auszuspähen
  * Es soll weiterhin eine begrenzte Traffic Flow Confidentiality geben
* Sicherheitsrichtlinie
  * Sender, Empfänger und zwischenliegende Knoten sollen erkennen können, ob ein Paket ihrer Sicherheitsrichtlinie entspricht und dieses gegebenenfalls verwerfen

#### IPSec: Sicherheitsassoziation
* Eine Sicherheitsassoziation (SA) it eine "Simplexverbindung" welche Sicherheitsdienste für den von ihr beförderten Verkehr anbietet
  * Sicherheitsdienste werden einer SA durch die Verwendung von entweder AH (Authentication Header) oder ESP (Encapsulating Security Payload) bereitgestellt
  * Für bidirektionale Kommunikation werden zwei SA benötigt
  * Eine SA ist eindeutig bestimmt durch ein Tripel, welches aus eine Sicherheitsparamterindex (SPI), einer Ziel-IP-Adresse und einem Sicherheitsprotokollbezeichner (AH/ESP) besteht
  * Eine SA kann zwischen folgenden Peers aufgebaut werden
    * Host <-> Host 
    * Host <-> Gateway
    * Gateway <-> Host
    * Gateway <-> Gateway
  * Es gibt zwei konzeptionelle Datenbanken, die mit SAs assoziiert werden
    * Die Sicherheitsrichtliniendatenbank (SPD), spezifiziert welche Sicherheitsdienste wie für IP Pakete bereitgestellt werden
    * Die Sicherheitsassoziationsdatenbank (SADB)

#### IPSec Protokollmodi
* Eine SA ist immer von einem der folgenden Typen: 
  * Der Transportmodus kann nur zwischen Endpunkten der Kommunikation verwendet werden
    * Host <-> Host
    * Host <-> Gateway (falls Gateway hier Kommunikationsendpunkt)
  * Der Tunnelmodus kann mit beliebigen Peers verwendet werden
* Unterschiede zwischen den Modi: 
  * Der Transportmodus fügt nur einen sicherheitsspezifischen Header hinzu (+ potentiellen Trailer)
  * Der Tunnelmodus kapselt IP Pakete
* Die Kapselung von IP-Paketen ermöglicht es den Gateways , Daten im Auftrag von anderen Instanzen zu schützen

#### IPSec: Verschachtelung von Sicherheitsassoziationen
Beispiel: Host A und Gateway RB führen Datenherkunftsauthentisierung aus und die Gateways RA und RB führen Subnetz-to-Subnetz Vertraulichkeit aus 

##### IPSec Authentication Header (AH)
* Im Tunnelmodus stellt der Payload nochmals ein ganzes IP Paket dar
* Wichtig: AH funktioniert nur in NAT freien Umgebungen

##### IPSec Encapsulating Security Protocol (ESP)
* Dem ESP Header folgt direkt ein IP Header oder ein AH-Header
* Das next-header Feld vom vorhergehenden Header indiziert 50 für ESP

#### IPSec: Etablierung von Sicherheitassoziationen
* Bevor ein Paket von IPSec geschützt wird, muss eine SA zwischen den beiden "kryptographischen Endpunkten", welche den Schutz bereitstellen, aufgebaut werden
* SA Etablierung kann auf folgende Arten geschehen
  * Manuell, durch proprietäre Methoden des Systemmanagements (nur in Ausnahmefällen)
  * Dynamisch, durch ein standardisiertes Authentisierungs- und Schlüsselmanagementprotokoll
* IPSec definiert eine standardisierte Methode für die Etablierung von SAs
  * Internet Security Association and Key Management Protocol (ISAKMP)
    * Definiert Protokollformate und Prozeduren für die Sicherheitsaushandlung
  * Internet Key Exchange (IKE)
    * Definiert IPSecs Standardauthentisierungs- und Schlüsselaustauschprotokoll

## Internetfirewalls
* Eine Netzwerkfirewall kann gut mit einer mittelalterlichen Zugbrücke verglichen werden: 
  * Sie beschränkt, welche Menschen die Burg betreten, da es nur den einen kontrollierten Eingang gibt
  * Sie hält Angreifer davon ab, zu den weiteren Schutzmaßnahmen vorzudringen
  * Sie beschränkt, welche Leute die Burg am streng überwachten Übergang verlassen 
* Typischerweise wird eine Firewall an einem Punkt installiert, dan dem ein geschützes Subnetz an ein weniger vertrauenswürdiges Netzwerk angeschlossen wird
* Grundsätzlich realisieren Firewalls also Zugriffskontrolle auf dem Subnetzlevel

### Terminologie
* Firewall: 
  * Eine oder eine Menge an Komponenten, welche den Zugriff zwischen einem geschützten Netzwerk und dem Internet oder zwischen einer Menge an Netzwerken beschränkt
* Paketfiltern/Screening: 
  * Die Aktion, welche ein Gerät ausführt, um selektiv den Fluss an Daten in und aus einem Netzwerk zu kontrollieren
  * Paketfiltern ist eine wichtige Technik um Zugriffskontrolle auf dem Subnetzwerklevel für paketorientierte Netzwerke zu implementieren
* Bastion Host: 
  * Ein Computer, welcher besonders gesichert werden muss, da er anfälliger für Angriffe ist, als andere Computer im Subnetz
  * Ein Bastion Host in einer Firewall ist typischerweise der Hauptansprechpartner für Nutzerprozesse von Hosts innerhalb des Netzwerks zu Prozessen von externen Hosts 
* Dual Homed Host 
  * Ein Computer mit > 2 Netzwerkinterfaces 
* Proxy: 
  * Ein Programm, welches sich im Auftrag interner Clients mit externen Servern beschäftigt
  * Proxies leiten genehmigte Clientanfragen an die Server, und die Antworten auch wieder an den Client weiter 
  * Wenn ein Proxy die Kommandos eines Anwendungsprotokollls versteht und interpretiert, dann ist es ein Application Level Proxy, andernfalls, falls er die PDUs nur zwischen Cient und Server weiterreicht, so ist es ein Circuit Level Proxy
* Network Address Translation (NAT): 
  * Eine Prozedur, durch welche ein Router die Daten in Paketen ändert um die Netzwerkadressen zu modifizieren
  * Dies erlaubt es die interne Netzwerkstruktur zu verschleiern
* Perimeternetzwerk
  * Ein Subnetz, welches zwischen einem externen und einem internen Netzwerk hinzugefügt wird, um eine weitere Sicherheitseben bereitzustellen
  * Ein Synonym hierfür ist DMZ (De Militarized Zone)

### Firewallarchitekturen
#### Einfache Paketfilterarchitektur
* Einfachste Architektur bestehend aus einem paketfilternden Router
* Realisierbar durch PC mit zwei Netzwerkinterfaces oder einem dedizierten Router 

#### Die Screened Host Architektur
* Der Paketfilter erlaubt zuverlässigen Verkehr zwischen dem screended Host und dem Internet und blockiert jeglichen Verkehr zwischen anderen internen Hosts  und dem Internet
* Der screened Host stellt Proxydienste bereit
  * Ungeachtet des teilweisen Schutz durch den Paketfilter, fungiert der screened Host als ein Bastion Host

#### Die Screened Subnet Architektur
* Ein Perimeternetzwerk wird zwischen zwei Paketfiltern installiert
* Der innere Paketfilter dient zum zusätzlichen Schutz im Falle, dass der Bastion Host je kompromittiert wird (so kann ein übernommener Bastion Host keinen internen Verkehr mithören)
* Dieses Perimeternetzwerk ist ebenfalls ein guter Ort, um einen öffentlich erreichbaren Server zu hosten

#### Firewalls: Paketfiltrierung
* Was kann man mit Paketfiltern alles erreichen? 
  * Theoretisch alles, da alle Informationen, welche in einer Kommunikation ausgetauscht werden  als Pakete transportiert werden
  * Praktisch allerdings, dient folgendes als Orientierungshilfe
    * Operationen, welche detaillierte Kenntnisse über Protokolle höherer Schichten erfordern, oder die verlängerte Nachverfolgung von vergangenen Ereignissen benötigen, sind in Proxysystemen einfacher zu realisieren
    * Operationen, die zwar einfach sind, aber sehr schnell ausgeführt werden müssen, sind in Paketfiltersystemen einfacher zu handhaben
* Grundlegendes Paketfiltern erlaubt es den Datentransfer anhand folgender Kriterien zu kontrollieren: 
  * Quell IP
  * Ziel IP
  * Transportprotokoll
  * Quell- und Zielanwendungsport 
  * Potentielle, spezifische Kontrollflags
  * Das Netzwerkinterface, auf welchem das Paket ankam
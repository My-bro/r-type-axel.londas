#Informations Server
[server]

port=8080 ;Port du Server

#Informations client
[Client]

port=8080 ;Port du Server

host=192.168.1.40 ;ip server



# Explication du Fichier de Configuration

Ce fichier de configuration permet de récupérer les paramètres pour un **serveur** et un **client**. Il utilise un format simple où chaque section est délimitée par des crochets `[ ]`, et les paramètres sont spécifiés sous la forme **clé=valeur**. Les commentaires sont indiqués par un point-virgule `;`.

---

## Structure du Fichier

### 1. Section `[server]`
Cette section contient les informations nécessaires pour configurer le **serveur**.

```ini
[server]
port=8080 ;Port du Server
```

**Détails :**
- **port** : Définit le port sur lequel le serveur écoute.  
  - **Valeur** : `8080`  
  - **Commentaire** : `;Port du Server`

---

### 2. Section `[Client]`
Cette section contient les informations nécessaires pour configurer le **client**.

```ini
[Client]
port=8080 ;Port du Server
host=192.168.1.40 ;ip server
```

**Détails :**
- **port** : Définit le port sur lequel le client se connecte.  
  - **Valeur** : `8080`  
  - **Commentaire** : `;Port du Server`
- **host** : Spécifie l'adresse IP du serveur auquel le client doit se connecter.  
  - **Valeur** : `192.168.1.40`  
  - **Commentaire** : `;ip server`

---

## Règles Générales

### 📌 Sections
- Les sections sont définies par des crochets `[ ]` (ex. `[server]` ou `[Client]`).

### 📌 Clés et Valeurs
- Les paramètres sont déclarés sous la forme **clé=valeur**.

### 📌 Commentaires
- Les commentaires commencent par un point-virgule `;`. Ils permettent d'expliquer les paramètres.

### 📌 Ports
- Le port `8080` est utilisé pour la communication entre le serveur et le client.

### 📌 Adresse IP
- Le client utilise l'adresse IP `192.168.1.40` pour se connecter au serveur.

---

**Exemple Complet :**

```ini
[server]
port=8080 ;Port du Server

[Client]
port=8080 ;Port du Server
host=192.168.1.40 ;ip server
```

---
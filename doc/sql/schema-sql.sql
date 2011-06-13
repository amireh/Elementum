/* SQLEditor (Postgres)*/
DROP TABLE matches;
DROP TABLE profiles;
DROP TABLE users;

CREATE TABLE profiles
(
id INTEGER UNIQUE,
Name VARCHAR(255),
Race VARCHAR(255),
Intelligence INTEGER DEFAULT 0,
Vitality INTEGER DEFAULT 0,
Alignment INTEGER DEFAULT 0,
Deck INTEGER[],
Talents INTEGER[][],
Wins INTEGER DEFAULT 0,
Losses INTEGER DEFAULT 0,
PRIMARY KEY (Name)
);

CREATE TABLE users
(
id SERIAL,
username VARCHAR(255) UNIQUE,
password VARCHAR(255),
isOnline BOOLEAN DEFAULT FALSE,
PRIMARY KEY (id)
);

CREATE TABLE matches
(
id INTEGER,
id_winner INTEGER,
id_loser INTEGER,
date TIMESTAMP,
PRIMARY KEY (id)
);

ALTER TABLE profiles ADD FOREIGN KEY (id) REFERENCES users (id);

ALTER TABLE matches ADD FOREIGN KEY (id_winner) REFERENCES profiles (id);

ALTER TABLE matches ADD FOREIGN KEY (id_loser) REFERENCES profiles (id);

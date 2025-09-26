import sqlite3



conexao = sqlite3.connect()
cursor = conexao.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS historico (
    id INTEGER,
    distancia REAL,
    estado TEXT,
    busca BOOLEAN,
    timestamp TEXT
)
""")

conexao.commit()
conexao.close()

print("✅ Banco e tabela criados com sucesso!")

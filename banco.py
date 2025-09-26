import sqlite3


caminho_banco = r"C:\Users\Vini\.node-red\motos.db"

conexao = sqlite3.connect(caminho_banco)
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

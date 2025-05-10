import subprocess
import sys

def instalar_requisitos(nome_arquivo):
    print(f"\n📦 Instalando pacotes a partir de: {nome_arquivo}\n")
    try:
        subprocess.check_call([sys.executable, "-m", "pip", "install", "-r", nome_arquivo])
    except subprocess.CalledProcessError as e:
        print(f"Erro ao instalar pacotes do {nome_arquivo}: {e}")
        sys.exit(1)

def detectar_gpu():
    try:
        import torch
        if torch.cuda.is_available():
            print("✅ CUDA disponível. Usando GPU.")
            return True
        else:
            print("⚠️ PyTorch instalado, mas CUDA não está disponível.")
            return False
    except ImportError:
        print("⚠️ PyTorch não está instalado ainda. Assumindo CPU.")
        return False

if __name__ == "__main__":
    usar_gpu = detectar_gpu()
    if usar_gpu:
        instalar_requisitos("requirements-gpu.txt")
    else:
        instalar_requisitos("requirements.txt")

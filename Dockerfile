# Utiliser une image Ubuntu de base
FROM ubuntu:latest

# Mettre à jour les paquets et installer les dépendances nécessaires
RUN apt-get update && \
    apt-get install -y \
    gcc \
    make \
    valgrind \
    curl \
    git \
    zsh

# Copier ton code source dans le conteneur
COPY . /workspace

# Définir le répertoire de travail dans le conteneur
WORKDIR /workspace

# Compiler ton programme avec gcc (en activant les informations de débogage avec -g)
RUN gcc -g -o mon_programme ft_printf.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_print_c.c ft_print_d.c ft_print_p.c ft_print_u.c ft_print_s.c ft_putchar_fd.c ft_print_xX.c

# Lancer Zsh par défaut (facultatif, mais pour avoir un shell interactif)
CMD ["zsh"]


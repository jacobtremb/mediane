import numpy as np
import pytest
import mediane


def test_donnees_repetees():
    """Erreur quand il y a des données répétées."""
    with pytest.raises(RuntimeError, match="Donnees repetees"):
        mediane.cum_mediane(np.array([1.0, 2.0, 1.0]))


def test_diapo():
    """La bonne sortie pour les 5 données de la diapo."""
    actual = mediane.cum_mediane(np.array([2, 3, 0, 1, 5]))
    expected = np.array([2, 2.5, 2, 1.5, 2])
    np.testing.assert_allclose(actual, expected)


def test_comme_numpy():
    """Même résultat que np.median sur chaque début du tableau."""
    donnees = np.random.default_rng(1).standard_normal(100)
    actual = mediane.cum_mediane(donnees)
    expected = np.array([np.median(donnees[:i + 1]) for i in range(len(donnees))])
    np.testing.assert_allclose(actual, expected)
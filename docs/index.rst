mediane
=======

Package Python qui calcule la médiane cumulative d'un tableau numpy.
L'algorithme est écrit en C++ et appelé depuis Python avec pybind11.

Installation
------------

.. code-block:: bash

   pip install ./mediane_pkg

Exemple
-------

.. code-block:: python

   >>> import numpy as np
   >>> import mediane
   >>> mediane.cum_mediane(np.array([2, 3, 0, 1, 5]))
   array([2. , 2.5, 2. , 1.5, 2. ])

Référence
---------

.. automodule:: mediane
   :members:
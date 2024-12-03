try:
    from .dsmga2 import DSMGA2, sweep, dsmga2
except ImportError as e:
    print(f"Error importing dsmga2 module: {e}")
    raise

__all__ = ['DSMGA2', 'sweep', 'dsmga2'] 

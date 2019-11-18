import React from 'react';
import { Router, Stack, Scene } from 'react-native-router-flux';

import Buttons from './screens/Buttons';
import Camera from './screens/Camera';

const App = () => (
  <Router>
    <Stack key="root" hideNavBar>
      <Scene key="buttons" component={Buttons} hideNavBar initial />
      <Scene key="camera" component={Camera} hideNavBar />
    </Stack>
  </Router>
);

export default App;

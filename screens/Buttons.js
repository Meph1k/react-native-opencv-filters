// @flow
import React, { Component } from "react";
import { NativeModules, StyleSheet, Text, Alert, Image, ScrollView, Button, Dimensions } from "react-native";
type Props = {};
type State = { message: string };
const { OpenCV } = NativeModules;
import { Actions } from 'react-native-router-flux';

export default class App extends Component<Props, State> {
  state = {
    message: ""
  };

  applyFilter = (func) => async (uri) => {
    try {
      const message = await func(uri);
      this.setState({
        message
      });
    } catch(e) {
      alert(e);
    }
  }

  getFilter = (func) => () => {
    this.setState({ message: 'loading...' })

    Alert.alert(
      'Filters',
      'About to apply a filter',
      [
        {text: 'Default photo', onPress: this.applyFilter(func)},
        {
          text: 'Cancel',
          onPress: () => null,
          style: 'cancel',
        },
        {text: 'Camera', onPress: () => {
            Actions.push('camera', { applyFilter: this.applyFilter(func)})
          }},
      ],
      {cancelable: false},
    );
  }

  getCanny = async (uri = '') => {
    return await OpenCV.getCanny(uri)
  }

  getThreshold = async (uri = '') => {
    return await OpenCV.getThreshold(uri);
  }

  getLines = async (uri = '') => {
    return await OpenCV.getLines(uri);
  }

  getContours = async (uri = '') => {
    return await OpenCV.getContours(uri);
  }

  getSegments = async (uri = '') => {
    return await OpenCV.getSegments(uri);
  }

  getRoundContours = async (uri = '') => {
    return await OpenCV.getRoundContours(uri);
  }

  render() {
    const { message } = this.state;
    return (
      <ScrollView>
        <Text style={styles.welcome}>Message from Native:</Text>
        <Button title="Get canny image" onPress={this.getFilter(this.getCanny)} />
        <Button title="Get basic threshold image" onPress={this.getFilter(this.getThreshold)} />
        <Button title="Get lines" onPress={this.getFilter(this.getLines)} />
        <Button title="Get contours" onPress={this.getFilter(this.getContours)} />
        <Button title="Get segments" onPress={this.getFilter(this.getSegments)} />
        <Button title="Get round contours" onPress={this.getFilter(this.getRoundContours)} />
        <Image
          source={{ uri: `data:image/png;base64,${message}` }}
          style={{ width: Dimensions.get('window').width, height: 300 }}
        />
      </ScrollView>
    );
  }
}
const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
    backgroundColor: "#F5FCFF"
  },
  welcome: {
    fontSize: 20,
    textAlign: "center",
    margin: 10
  }
});

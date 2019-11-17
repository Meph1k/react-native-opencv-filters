// @flow
import React, { Component } from "react";
import { NativeModules, StyleSheet, Text, View, Image, ScrollView, Button, Dimensions } from "react-native";
type Props = {};
type State = { message: string };
const { OpenCV } = NativeModules;
export default class App extends Component<Props, State> {
  state = {
    message: ""
  };

  getCanny = async () => {
    this.setState({ message: 'loading...' })

    try {
      const message = await OpenCV.getCanny();
      this.setState({
        message
      });
    } catch(e) {
      alert(e);
    }
  }

  getThreshold = async () => {
    this.setState({ message: 'loading...' })

    try {
      const message = await OpenCV.getThreshold();
      this.setState({
        message
      });
    } catch(e) {
      alert(e);
    }
  }

  getLines = async () => {
    this.setState({ message: 'loading...' })

    try {
      const message = await OpenCV.getLines();
      this.setState({
        message
      });
    } catch(e) {
      alert(e);
    }
  }

  getContours = async () => {
    this.setState({ message: 'loading...' })

    try {
      const message = await OpenCV.getContours();
      this.setState({
        message
      });
    } catch(e) {
      alert(e);
    }
  }

  getSegments = async () => {
    this.setState({ message: 'loading...' })

    try {
      const message = await OpenCV.getSegments();
      this.setState({
        message
      });
    } catch(e) {
      alert(e);
    }
  }

  getRoundContours = async () => {
    this.setState({ message: 'loading...' })

    try {
      const message = await OpenCV.getRoundContours();
      this.setState({
        message
      });
    } catch(e) {
      alert(e);
    }
  }

  render() {
    const { message } = this.state;
    return (
      <ScrollView>
        <Text style={styles.welcome}>Message from Native:</Text>
        <Button title="Get canny image" onPress={this.getCanny} />
        <Button title="Get basic threshold image" onPress={this.getThreshold} />
        <Button title="Get lines" onPress={this.getLines} />
        <Button title="Get contours" onPress={this.getContours} />
        <Button title="Get segments" onPress={this.getSegments} />
        <Button title="Get round contours" onPress={this.getRoundContours} />
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

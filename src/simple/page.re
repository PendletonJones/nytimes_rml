/* ::name is a syntax shorthand for name::name, so a label attached to a variable that you can refer
to it as in the body of the function. */
type action =
  | Click
  | Toggle;

type state = {count: int, show: bool};

let component = ReasonReact.reducerComponent "MyDialog";
let make _children => {
  ...component,
  initialState: fun () => {count: 0, show: false},
  reducer: fun action state =>
    switch action {
    | Click => ReasonReact.Update {...state, count: state.count + 1}
    | Toggle => ReasonReact.Update {...state, show: not state.show}
    },
  render: fun self => {
    let message = "Clicked " ^ string_of_int self.state.count ^ " times(s)";
    <div>
      <div
        style=(ReactDOMRe.Style.make
          color::"#444444"
          fontSize::"68px"
          ()
        )
        onClick=(self.reduce (fun _event => Click))
        onSubmit=(self.reduce (fun _event => Toggle))>
        (ReasonReact.stringToElement "click me")
      </div>
      (ReasonReact.stringToElement message)
      (ReasonReact.stringToElement "Hello World")
    </div>
  }
}
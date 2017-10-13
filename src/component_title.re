module Make (Meta: MetaTags.Interface) => {
  let component = ReasonReact.statelessComponent "Title";
  let make ::title _children => {
    ...component,
    render: fun _ => {
      Meta.set_title title; /* It would be better to have this side effect in `didMount` but `didMount` is not called in server side rendering. See https://github.com/reasonml/reason-react/issues/95 */
      <div />
    }
  };
};